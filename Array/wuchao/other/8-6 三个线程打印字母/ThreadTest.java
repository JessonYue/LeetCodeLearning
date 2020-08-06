package com.slow.lib.practice.others;

/**
 * @Author wuchao
 * @Date 2020/8/4-8:57 PM
 * @description
 * @email 329187218@qq.com
 * @see
 */
public class ThreadTest {
    private volatile Object lock = new Object();
    private volatile int index = 0;
    private int current = 0;

    public static void main(String[] args) {
        ThreadTest test = new ThreadTest();

        test.test();
    }

    private void test() {
        Thread threadA = new Thread(print);
        threadA.setName("1");
        Thread threadB = new Thread(print);
        threadB.setName("2");
        Thread threadC = new Thread(print);
        threadC.setName("3");
        threadA.start();
        threadB.start();
        threadC.start();
    }

    Runnable print = () -> printLetter();


    public void printLetter() {
        synchronized (lock) {
            String name = Thread.currentThread().getName();
            while (index < 26) {
                while (name.equals("1") && current != 0 || name.equals("2") && current != 1 || name.equals("3") && current != 2) {
                    try {
                        lock.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                if(index==26){
                    return;
                }
                System.out.println("Thread " + Thread.currentThread().getName() + ":" + (char) ('A' + index));
                index++;
                current = (current + 1) % 3;
                lock.notifyAll();
            }
        }
    }
}
