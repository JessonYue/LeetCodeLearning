package homework.h0804_0809;

import java.util.concurrent.Semaphore;

public class homework6_thread {

    public static void main(String[] args) {
        //final Object lock = new Object();
//        ThreadA t1 = new ThreadA(lock);
//        ThreadB t2 = new ThreadB(lock);
//        ThreadC t3 = new ThreadC(lock);
//        t1.start();
//        t2.start();
//        t3.start();

        try {
            B.acquire();    //保证A优先执行
            C.acquire();
            new ThreadA().start();
            new ThreadB().start();
            new ThreadC().start();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

//    public static class ThreadA extends Thread{
//        private final Object lock;
//        public ThreadA(Object lock) {
//            // TODO Auto-generated constructor stub
//            this.lock = lock;
//        }
//
//        @Override
//        public void run() {
//            for (int i = 1; i <= 26; i++) {
//                synchronized (lock) {
//                    lock.notify();
//                    try {
//                        lock.wait(4L);
//                    } catch (InterruptedException e) {
//                        // TODO Auto-generated catch block
//                        e.printStackTrace();
//                    }
//                    System.out.print(String.valueOf(i));
//                    lock.notify();
//                }
//            }
//
//        }
//    }
//
//    public static class ThreadB extends Thread{
//        private final Object lock;
//        public ThreadB(Object lock) {
//            // TODO Auto-generated constructor stub
//            this.lock = lock;
//        }
//
//        @Override
//        public void run() {
//
//            char[] string = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','w','r','s','t','u','v','w','x','y','z'};
//            for (int i = 0; i < string.length; i++) {
//                synchronized (lock) {
//                    lock.notify();
//                    try {
//                        lock.wait(5L);
//                    } catch (InterruptedException e) {
//                        // TODO Auto-generated catch block
//                        e.printStackTrace();
//                    }
//                    System.out.print(string[i]);
//                    lock.notify();
//                }
//            }
//
//
//        }
//    }
//    public static class ThreadC extends Thread{
//        private final Object lock;
//        public ThreadC(Object lock) {
//            // TODO Auto-generated constructor stub
//            this.lock = lock;
//        }
//
//        @Override
//        public void run() {
//            for (int i = 0; i < 25; i++) {
//                synchronized (lock) {
//                    lock.notify();
//                    try {
//                        lock.wait();
//                    } catch (InterruptedException e) {
//                        // TODO Auto-generated catch block
//                        e.printStackTrace();
//                    }
//                    System.out.print(",");
//                    lock.notify();
//                }
//            }
//
//
//        }
//    }

    private static Semaphore A = new Semaphore(1);
    private static Semaphore B = new Semaphore(1);
    private static Semaphore C = new Semaphore(1);

    static class ThreadA extends Thread {

        @Override
        public void run() {
            try {
                for (int i = 1; i <= 26; i++) {
                    A.acquire();
                    System.out.print(String.valueOf(i));
                    B.release();
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }

    static class ThreadB extends Thread {

        @Override
        public void run() {
            try {
                char[] string = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','w','r','s','t','u','v','w','x','y','z'};
                for (int i = 0; i < string.length; i++) {
                    B.acquire();
                    System.out.print(String.valueOf(string[i]));
                    C.release();
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }

    static class ThreadC extends Thread {

        @Override
        public void run() {
            try {
                for (int i = 0; i < 25; i++) {
                    C.acquire();
                    System.out.println(",");
                    A.release();
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }


}
