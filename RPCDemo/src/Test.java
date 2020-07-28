import java.io.IOException;
import java.net.InetSocketAddress;

public class Test {

    public static void main(String[] args) {
//        // 线程池
//        ExecutorService exec = Executors.newCachedThreadPool();
//        // 只能5个线程同时访问
//        final Semaphore semp = new Semaphore(5);
//        // 模拟20个客户端访问
//        for (int index = 0; index < 20; index++) {
//            final int NO = index;
//            Runnable run = new Runnable() {
//                public void run() {
//                    try {
//                        // 获取许可
//                        semp.acquire();
//                        System.out.println("Accessing: " + NO);
//                        Thread.sleep((long) (Math.random() * 10000));
//                        // 访问完后，释放
//                        semp.release();
//                        System.out.println("-----------------"+semp.availablePermits());
//                    } catch (InterruptedException e) {
//                        e.printStackTrace();
//                    }
//                }
//            };
//            exec.execute(run);
//        }
//        // 退出线程池
//        exec.shutdown();


        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    Server serviceServer = new ServerCenter(8088);
                    serviceServer.register(ServiceProducer.class, ServiceProducerImpl.class);
                    serviceServer.start();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }).start();
        ServiceProducer service = RPCClient.getRemoteProxyObj(ServiceProducer.class, new InetSocketAddress("localhost", 8088));
        System.out.println(service.sendData("test"));

        //耦合度太高，spring ioc
        ServiceProducer serviceProducer = new ServiceProducerImpl();
        serviceProducer.sendData("hello java");
    }
}
