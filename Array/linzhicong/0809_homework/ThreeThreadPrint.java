package com.example.myapplication.threethreadprint;

//import android.util.Log;

public class ThreeThreadPrint {

    private static final String TAG = ThreeThreadPrint.class.getSimpleName();

    private static final int THREAD_1 = 1;
    private static final int THREAD_2 = 2;
    private static final int THREAD_3 = 3;
    //当前轮到哪个线程打印
    private int curThread = THREAD_1;

    private final byte[] lock = new byte[]{};

    private char mChar = 'A';

    Thread thread1 = new Thread(new Runnable() {
        @Override
        public void run() {
            while (true) {
                synchronized (lock) {
                    if (curThread == THREAD_1) {
//                        Log.d(TAG, "Thread-1 Name : " + thread1.getName() + "  mChar = " + mChar++);
                        System.out.println("Thread-1 Name : " + thread1.getName() + "  mChar = " + mChar++);
                        if (mChar == 'Z' + 1) {
                            break;
                        }
                        curThread = THREAD_2;
                    }
                }
            }
        }
    });

    Thread thread2 = new Thread(new Runnable() {
        @Override
        public void run() {
            while (true) {
                synchronized (lock) {
                    if (curThread == THREAD_2) {
//                        Log.d(TAG, "Thread-2 Name : " + thread2.getName() + "  mChar = " + mChar++);
                        System.out.println("Thread-2 Name : " + thread2.getName() + "  mChar = " + mChar++);
                        if (mChar == 'Z' + 1) {
                            break;
                        }
                        curThread = THREAD_3;
                    }
                }
            }
        }
    });

    Thread thread3 = new Thread(new Runnable() {
        @Override
        public void run() {
            while (true) {
                synchronized (lock) {
                    if (curThread == THREAD_3) {
//                        Log.d(TAG, "Thread-3 Name : " + thread3.getName() + "  mChar = " + mChar++);
                        System.out.println("Thread-3 Name : " + thread3.getName() + "  mChar = " + mChar++);
                        if (mChar == 'Z' + 1) {
                            break;
                        }
                        curThread = THREAD_1;
                    }
                }
            }
        }
    });

    public void start() {
        thread1.start();
        thread2.start();
        thread3.start();
    }
}
