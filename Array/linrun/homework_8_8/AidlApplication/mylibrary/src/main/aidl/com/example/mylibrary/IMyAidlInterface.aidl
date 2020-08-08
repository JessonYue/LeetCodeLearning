// IMyAidlInterface.aidl
package com.example.mylibrary;

// Declare any non-default types here with import statements

interface IMyAidlInterface {
    /**
     * Demonstrates some basic types that you can use as parameters
     * and return values in AIDL.
     */
    int plus(int a, int b);
    int getCount(String source);
    void putParem(in Map data);
}
