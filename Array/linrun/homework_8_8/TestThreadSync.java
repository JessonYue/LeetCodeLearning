package com.dn_alan.myapplication.rxjava;

/**
 * date:2020/8/8
 * description:
 * author:rlin
 */
class TestThreadSync {

    int num = 1;
    char c = 'A';
    public void testMyCode() {
        final byte[] lock = new byte[0];

        for (int i = 0; i < 3; i++) {
            new Thread() {
                @Override
                public void run() {
                    while (num <= 26) {
                        synchronized (lock) {
                            if (num > 26) {
                                break;
                            }
                            System.out.println("Thread:" + Thread.currentThread().getId() + "------------" + String.valueOf(num) + c);
                            num++;
                            c++;
                        }
                    }

                }
            }.start();
        }
    }

}
