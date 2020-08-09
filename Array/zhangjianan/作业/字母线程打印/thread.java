package com.example.test;

import org.junit.Test;

public class thread {
    volatile  static  int i = 0;
    volatile  char str = 'A';
    private volatile Object lock = new Object();

    @Test
    public void addition_isCorrect() {
        new Thread(new MyThread(), "1").start();
        new Thread(new MyThread(), "2").start();
        new Thread(new MyThread(), "3").start();
    }

    class MyThread implements Runnable {
        @Override
        public void run() {
            synchronized (lock) {
                try {
                    int index = Integer.valueOf(Thread.currentThread().getName());
                    for (; i < 26;) {
                        if (i % 3 == index - 1) {
                            System.out.println((char) (str+i)+ "--------" + Thread.currentThread().getName());
                            i++;
                            lock.notifyAll();
                        } else {
                            lock.wait();
                        }
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
}
}