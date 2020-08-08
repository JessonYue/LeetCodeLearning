package com.lanfairy.md.eight;

public class myThread {
    private volatile static char c = 'A';

    private volatile static int count = 0;

    public static void main(String[] args) {
        method();
    }

    /**
     * 一个多线程的问题，用三个线程，顺序打印字母A-Z，输出结果是1A 2B 3C 1D 2E...
     */
    public static void method() {
        Runnable r = new Runnable() {
            @Override
            public void run() {
                synchronized (this) {
                    try {
                        int threadId = Integer.parseInt(Thread.currentThread().getName());
                        while (count < 26) {
                            if (count % 3 == threadId - 1) {
                                System.out.println( threadId + "" + (char) (c++));
                                count++;
                                notifyAll();
                            } else {
                                wait();
                            }
                        }

                    } catch (Exception e) {

                    }
                }

            }
        };
        new Thread(r, "1").start();
        new Thread(r, "2").start();
        new Thread(r, "3").start();
    }
}
