package com.andy.leddemo;

import android.os.IBinder;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.Toast;

import java.lang.reflect.Method;
import android.os.ILedService;
import android.os.ServiceManager;

public class MainActivity extends AppCompatActivity {

    private boolean ledon = false;
    private Button mBtn;
    private CheckBox led1;
    private CheckBox led2;
    private CheckBox led3;
    private CheckBox led4;
    private Object mProxy;
    private Method mLedCtrl;
    private ILedService mILedService;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mBtn = findViewById(R.id.btn);
        public static IBinder getService(String name)
        mILedService = ILedService.Stub.asInterface(ServiceManager.getService("led"));      
        } catch (Exception e) {
            e.printStackTrace();
            Log.d("lcx", "onCreate: "+e.toString());
        }
        led1 = findViewById(R.id.led1);
        led2 = findViewById(R.id.led2);
        led3 = findViewById(R.id.led3);
        led4 = findViewById(R.id.led4);
    }

    public void clickall(View view) {
        ledon = !ledon;
        if(ledon){
            mBtn.setText("ALL OFF");
            led1.setChecked(true);
            led2.setChecked(true);
            led3.setChecked(true);
            led4.setChecked(true);
            try {
                for (int i = 0; i < 4; i++) {
                    mILedService.ledCtrl(i,1);                
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }else{
            mBtn.setText("ALL ON");
            led1.setChecked(false);
            led2.setChecked(false);
            led3.setChecked(false);
            led4.setChecked(false);
            try {
                for (int i = 0; i < 4; i++) {
                    mLedCtrl.invoke(mProxy,i,0);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public void onCheckboxClicked(View view) {
        boolean checked = ((CheckBox)view).isChecked();
        try {
            switch (view.getId()){
                case R.id.led1:
                    if (checked){
                        Toast.makeText(this, "led1 on", Toast.LENGTH_SHORT).show();
                        mILedService.ledCtrl(0,1);
                    }else{
                        Toast.makeText(this, "led1 off", Toast.LENGTH_SHORT).show();
                        mILedService.ledCtrl(0,0);
                    }
                    break;

                case R.id.led2:
                    if (checked){
                        Toast.makeText(this, "led2 on", Toast.LENGTH_SHORT).show();
                        mILedService.ledCtrl(1,1);
                    }else{
                        Toast.makeText(this, "led2 off", Toast.LENGTH_SHORT).show();
                        mILedService.ledCtrl(1,0);
                    }
                    break;

                case R.id.led3:
                    if (checked){
                        Toast.makeText(this, "led3 on", Toast.LENGTH_SHORT).show();
                        mILedService.ledCtrl(2,1);

                    }else{
                        Toast.makeText(this, "led3 off", Toast.LENGTH_SHORT).show();
                        mILedService.ledCtrl(2,0);
                    }
                    break;

                case R.id.led4:
                    if (checked){
                        Toast.makeText(this, "led4 on", Toast.LENGTH_SHORT).show();
                        mILedService.ledCtrl(3,1);

                    }else{
                        Toast.makeText(this, "led4 off", Toast.LENGTH_SHORT).show();                        
						mILedService.ledCtrl(3,0);

                    }
                    break;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
//I/LedService: native ledCtrl : 1, 0, 0