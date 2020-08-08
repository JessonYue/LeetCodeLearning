package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import com.example.mylibrary.IMyAidlInterface;

import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.view.View;
import android.widget.Toast;

import java.util.HashMap;
import java.util.Map;

public class MainActivity extends AppCompatActivity {
    IMyAidlInterface iMyAidlInterface;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Intent intent = new Intent(this, MyService.class);
        bindService(intent, new ServiceConnection() {
            @Override
            public void onServiceConnected(ComponentName name, IBinder service) {
                System.out.println("onServiceConnected");
                iMyAidlInterface = IMyAidlInterface.Stub.asInterface(service);
            }

            @Override
            public void onServiceDisconnected(ComponentName name) {

            }
        }, BIND_AUTO_CREATE);

    }


    public void plus(View view) {
        System.out.println("click plus");
        if(iMyAidlInterface != null){
            try {
                int plus = iMyAidlInterface.plus(10, 20);
                Toast.makeText(this, "plus result:"+ plus, Toast.LENGTH_SHORT).show();
            } catch (RemoteException e) {
                e.printStackTrace();
            }
        }
    }

    public void translateString(View view) {
        System.out.println("click translateString");
        if(iMyAidlInterface != null){
            try {
                int count = iMyAidlInterface.getCount("gheuiwis");
                Toast.makeText(this, "getCount result:"+ count, Toast.LENGTH_SHORT).show();
            } catch (RemoteException e) {
                e.printStackTrace();
            }
        }
    }

    public void translateMap(View view) {
        System.out.println("click translateMap");
        if(iMyAidlInterface != null){
            try {
                Map<java.io.Serializable, java.io.Serializable> map = new HashMap<>();
                map.put(1, "H");
                map.put("2", 10);
                iMyAidlInterface.putParem(map);
            } catch (RemoteException e) {
                e.printStackTrace();
            }
        }
    }
}