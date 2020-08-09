package com.android.server;
import android.os.ILedService;

import android.hardware.input.InputManager;

public class LedService extends ILedService.Stub {
    private static final String TAG = "LedService";

    /*call native c function to access hardware*/
    public int ledCtrl(int which, int status) throws android.os.RemoteException{

        return native_ledCtrl(which,status);
    }

    public LedService(){
        native_ledOpen();
        //native_ledClose();
    }

    public static native int native_ledCtrl(int which, int status);
    public static native int native_ledOpen();
    public static native void native_ledClose();


}
