package com.example.myapplication;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;

import com.example.mylibrary.IMyAidlInterface;

import java.util.Map;

import androidx.annotation.Nullable;

/**
 * date:2020/8/8
 * description:
 * author:rlin
 */
public class MyService extends Service {

    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return new IMyAidlInterface.Stub() {
            @Override
            public int plus(int a, int b) throws RemoteException {
                int result = a + b;
                System.out.println("result:" + result);
                return result;
            }

            @Override
            public int getCount(String source) throws RemoteException {
                return source == null ? 0 : source.length();
            }

            @Override
            public void putParem(Map data) throws RemoteException {
                if (data == null) {
                    return;
                }
                for (Object key : data.keySet()) {
                    System.out.println("key:" + key + "-value:" + data.get(key));
                }
            }
        };
    }
}
