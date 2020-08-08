# InterfaceLoader 源码阅读笔记

## 概述

InterfaceLoader 是针对 aidl 的使用，做了一层封装，让使用者能够简单快速的实现aidl。这个库需要对 rxjava  有一个简单的了解。

## 使用实例

在 build.gradle  中添加依赖：

```
    implementation 'com.jeremyliao:interface-loader:0.0.1'
    implementation 'com.jeremyliao:service-fetcher-rxjava2:0.0.1'
```

写一个接口类 ILoaderDemo.java

```
public interface ILoaderDemo {
    int plus(int a, int b);
    int minus(int a, int b);
    int multi(int a, int b);
}
```

Service 端的 LoaderDemoService.java

```
public class LoaderDemoService extends Service {
    @Override
    public IBinder onBind(Intent intent) {
        return InterfaceService.newService(ILoaderDemo.class, new ILoaderDemo() {
            @Override
            public int plus(int a, int b) {
                return a+b;
            }

            @Override
            public int minus(int a, int b) {
                return b-a;
            }

            @Override
            public int multi(int a, int b) {
                return a*b;
            }
        });
    }
}
```

Client 端的Activity InterfaceLoadDemoActivity.java

```
    public void tvbind(View view) {
        Intent intent = new Intent(InterfaceLoadDemoActivity.this,LoaderDemoService.class);
        intent.setPackage(getPackageName());
        serviceFetcher = new ServiceFetcher(this, intent);
        serviceFetcher.bindService();
    }
    
    // 简单写其中一个方法
    public void tvplus(View view) {
        disposable.add(serviceFetcher.getService()
                .map(new Function<IBinder, Integer>() {
                    @Override
                    public Integer apply(IBinder binder) throws Exception {
                        return InterfaceLoader.getService(ILoaderDemo.class, binder)
                                .plus(10, 20);
                    }
                })
                .map(new Function<Integer, String>() {
                    @Override
                    public String apply(Integer result) throws Exception {
                        return "result: " + result;
                    }
                })
                .subscribe(new Consumer<String>() {
                    @Override
                    public void accept(String result) throws Exception {
                        tvContent.setText(result);
                    }
                }));
    }
    
```



## 分析源码

### 1、先来分析是如何bindService

```
        serviceFetcher = new ServiceFetcher(this, intent);
        serviceFetcher.bindService();
```

ServiceFetcher 是对 bindService 做了一层封装，来看看它的代码：

```
    private IBinder binder;
    private ServiceConnection connection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            binder = service;
            for (OnServiceConnectionListener listener : connectionListeners) {
                listener.onServiceConnected(service);
            }
            connectStatus = ConnectStatus.CONNECTED;
        }

        @Override
        public void onServiceDisconnected(ComponentName name) {
            binder = null;
            connectStatus = ConnectStatus.NOT_CONNECT;
        }
    };

	public ServiceFetcher(Context context, Intent intent, int flags) {
        this.context = context;
        this.intent = intent;
        this.flags = flags;
    }

    public ServiceFetcher(Context context, Intent intent) {
        this(context, intent, Context.BIND_AUTO_CREATE);
    }

	// 后面会用到，返回一个 Observable<IBinder>，配合着 rxjava 使用
    public Observable<IBinder> getService() {
        if (connectStatus == ConnectStatus.NOT_CONNECT) {
            bindService();
            return new ServiceFetchObservable(ServiceFetcher.this);
        } else if (connectStatus == ConnectStatus.CONNECTING) {
            return new ServiceFetchObservable(ServiceFetcher.this);
        } else {
            return Observable.just(binder);
        }
    }

    public void bindService() {
        if (connectStatus == ConnectStatus.NOT_CONNECT) {
            context.bindService(intent, connection, flags);
            connectStatus = ConnectStatus.CONNECTING;
        }
    }

    public void unbindService() {
        if (connectStatus == ConnectStatus.NOT_CONNECT) {
            return;
        }
        context.unbindService(connection);
        connectStatus = ConnectStatus.NOT_CONNECT;
    }
```

这里的代码应该容易理解，创建一个 ServiceFetcher 对象，然后 bindService ，绑定成功，则把状态改为 ConnectStatus.CONNECTED。

ConnectStatus 是 ServiceFetcher 下的一个枚举类，它有三个状态：NOT_CONNECT、CONNECTING 和 CONNECTED；

### 2、调用 Service 的方法

1）通过 serviceFetcher.getService() 拿到 ServiceFetchObservable，这是一个 Observable<IBinder>，这里其实就是为了拿到 Service 端返回的 IBinder 对象；

2）拿到了 IBinder 对象后，通过 InterfaceLoader.getService(ILoaderDemo.class, binder) 拿到 ILoaderDemo 的一个代理对象，这样我们就可以进行愉快的调用 Service 端的方法了；

### 3、着重看 InterfaceLoader.getService(class, binder)

```
public final class InterfaceLoader {
    @SuppressWarnings("unchecked")
    public static <T> T getService(final Class<T> service, final IBinder binder) {
        Utils.validateServiceInterface(service);
        return (T) Proxy.newProxyInstance(service.getClassLoader(),
                new Class[]{service},
                new InterfaceHandler(service, binder));
    }
}
```

可以看到，这里使用了动态代理的方式，实现在调用 ILoaderDemo 的方法的时候，转为调用 IBinder 的方法，即调用 Service 端的方法。

### 4、现在来看看 Service 端的代码

主要是 InterfaceService.newService(ILoaderDemo.class, new ILoaderDemo()) 方法:

```
public class InterfaceService<T> extends Binder {

    public static <R> InterfaceService<R> newService(Class<R> interfaceType, R implement) {
        Utils.validateServiceInterface(interfaceType);
        return new InterfaceService<>(interfaceType, implement);
    }

    private final Class<T> interfaceType;
    private final T implement;
    private String descriptor;

    private InterfaceService(Class<T> interfaceType, T implement) {
        this.interfaceType = interfaceType;
        this.implement = implement;
        this.descriptor = interfaceType.getName();
    }

    @Override
    protected boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
        data.enforceInterface(descriptor);
        Method method = getMethod(code);
        Object[] params = getParams(method, data);
        try {
            Object result = method.invoke(implement, params);
            if (reply != null) {
                reply.writeNoException();
                if (!(method.getReturnType().equals(Void.TYPE))) {
                    reply.writeValue(result);
                }
            }
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            throw new InterfaceLoadException(e);
        }
    }
}
```

概括下这里的代码：

- 1、newService 的时候，即创建一个 InterfaceService 对象，把 ILoaderDemo 的实例对象赋值给 InterfaceService 的 implement 成员变量;
- 2、在 client 端通过 aidl 调用 Service 端的接口方法时，会走到 InterfaceService 的 onTransact() 方法；
- 3、然后在 InterfaceService 的 onTransact() 方法里，通过反射的方式，调用到 implement 对象的方法。这里就相当于调用了 LoaderDemoService 中 ILoaderDemo 实例的方法；



## 总结流程

1、在 Service 端返回一个 InterfaceService 的 IBinder 对象；

2、Client 端通过绑定服务，拿到这个IBinder 对象，再通过动态代理的方式，实现 Service 端的调用，即调用 InterfaceService；

3、而 InterfaceService 的调用又转变为 Service 中 ILoaderDemo 实例的方法调用；





