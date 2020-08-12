package com.zqg.threadlibrary;

/**
 * <pre>
 *     author: zhuqiguang
 *     date  : 2020/8/11 10:57
 *     email : qiguang.zhu@foxmail.com
 *     desc  : TODO
 * </pre>
 */
class PrintThread {
    private volatile static int index = 0;
    private volatile static char aChar = 'A';
    private final static Object object = new Object();

    public static void main(String[] args) {
        new Thread(new Run(), "1").start();
        new Thread(new Run(), "2").start();
        new Thread(new Run(),  "3").start();
    }

    private static class Run implements Runnable{


        @Override
        public void run() {
            synchronized (PrintThread.class) {
                int threadNo = Integer.valueOf(Thread.currentThread().getName());
                while (index < 26) {
                    if (index % 3 == threadNo -1) {
                        System.out.println(threadNo + " " +  (char)(aChar++));
                        index++;
                        PrintThread.class.notifyAll();
                    }else {
                        try {
                            PrintThread.class.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }

        }
    }
}
