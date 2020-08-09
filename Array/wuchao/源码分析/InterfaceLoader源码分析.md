## InterfaceLoader源码解析

### 简介

* github地址:https://github.com/JeremyLiao/InterfaceLoader
* 作用:用以android IPC 调用，替代AIDL。

### 原理

本质还是用了binder机制，通过动态代理调用接口定义的方法。

先梳理一下AIDL的IPC流程，我们知道AIDL的IPC方式是生成了一个接口同名的Java类，里面通过静态代理的方式，用代理类实现了接口定义的方法，通过Binder类的transact方法，将传递的参数和代表这个接口类的描述字符串（即包名加名称）包裹进Pracel，传递过去，调用远程的目标方法。而被调用端同样有一份这样的AIDL文件和同样生成的接口同名Java类，这个类中的Stub类中onTransact方法，是如果发生远程方法调用就会走这个回调，这里取出参数，然后调用具体实现的方法。

这个库只不过用动态代理代替了静态代理。被调用端在onTransact回调中用transact code，然后通过反射找出要调用的函数，通过Method.invoke方法，传入具体实现和参数，实现调用。而调用端则是用动态代理，在方法调用的时候，根据方法的顺序生成transact code，然后通过Binder 类的transact方法来远程调用。说白了就是调用方通过方法顺序产生的下标index加上IBinder.FIRST_CALL_TRANSACTION来生成transact code来标记是哪个方法，而被调用方通过transact code 算出方法的下标，就可以知道调用的是哪个方法了。这样来看，调用方和被调用方都需要相同的接口类，如果两个类不一致，例如接口顺序不一致，或接口数量不一致等，调用就会发生错误。

### 流程分析

#### Client端

 * 定义远程调用的接口类

   ```
   public interface ILoaderDemo {
   
       int plus(int a, int b);
   
       int minus(int a, int b);
   
       int multi(int a, int b);
   }
   ```

* 通过动态代理生成接口实现

  ```
  public static <T> T getService(final Class<T> service, final IBinder binder) {
          Utils.validateServiceInterface(service);
          return (T) Proxy.newProxyInstance(service.getClassLoader(),
                  new Class[]{service},
                  new InterfaceHandler(service, binder));
      }
  ```

  看一下InterfaceHandler这个类，实现了InvocationHandler接口，在invoke方法里调用了Binder 的transact方法，发起远程调用

  ```
  @Override
      public Object invoke(Object o, Method method, Object[] objects) throws Throwable {
          int index = getIndex(method);
          if (index == -1) {
              return null;
          }
          Parcel data = Parcel.obtain();
          Parcel reply = Parcel.obtain();
          writeDescriptor(data);
          writeParams(data, objects);
          try {
              binder.transact(index, data, reply, 0);
              reply.readException();
              if (method.getReturnType().equals(Void.TYPE)) {
                  return null;
              } else {
                  return reply.readValue(getClass().getClassLoader());
              }
          } catch (RemoteException e) {
              e.printStackTrace();
          } finally {
              data.recycle();
              reply.recycle();
          }
          return null;
      }
  ```

  主要看getIndex方法，里面根据接口的方法的顺序生成了index，以这个作为方法的标记符。

  ```
  private int getIndex(Method method) {
          Method[] methods = service.getDeclaredMethods();
          for (int i = 0; i < methods.length; i++) {
              if (method.equals(methods[i])) {
                  return IBinder.FIRST_CALL_TRANSACTION + i;
              }
          }
          return -1;
      }
  ```

  至此，远程调用就传递给了Binder，Binder来请求服务端。

  

#### Service端

 * 用一个类继承Binder类，重写onTransact方法。因为远程方法调用最终会走道这个回调，需要在这个回调里面调用具体的方法。

   ```
   @Override
       protected boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
           data.enforceInterface(descriptor);
           Method method = getMethod(code);
           Object[] params = getParams(method, data);
           try {
           		//传入具体实现和参数实现方法的调用
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
   ```

   这里先是根据code，拿到具体接口实现的方法，具体看一下getMethod方法：

   ```
   private Method getMethod(int code) {
           int index = code - IBinder.FIRST_CALL_TRANSACTION;
           //反射获取接口定义的所有方法
           Method[] methods = interfaceType.getDeclaredMethods();
           if (index < 0 || index >= methods.length) {
               throw new InterfaceLoadException("Get method, index out of bounds!");
           }
           //返回匹配的方法
           return methods[index];
       }
   ```

   跟根据Client端传递过来的code，也就是方法标记符，解析出接口定义中具体的方法。通过反射传入具体实现对象和参数完成方法调用。

* 用一个类继承Service，在onBind中实例化这个Binber实现，实现调用的接口方法。

  ```
  @Override
      public IBinder onBind(Intent intent) {
          return InterfaceService.newService(ILoaderDemo.class, new ILoaderDemo() {
              @Override
              public int plus(int a, int b) {
                  return a + b;
              }
  
              @Override
              public int minus(int a, int b) {
                  return a - b;
              }
  
              @Override
              public int multi(int a, int b) {
                  return a * b;
              }
          });
      }
  ```

  

### 总结

总的来看这个库的IPC调用流程和AIDL的流程是一样的，只不过具体调用到方法的代码实现不一样，AIDL是自动生成每个方法的具体实现，用静态代理来调动具体的方法。而这个库用的是动态代理，根据接口方法顺序标记方法，从而实现具体的调用。两者都需要Client端和Service端有相同的接口定义，相比而言，这个库更加灵活。本质都是用到了Binder机制。

