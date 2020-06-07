package com.example.myapplication;

import android.util.Log;

public class OneDay {

    public void testVoid(int[]numbs,int target){
    if(null==numbs||numbs.length==0){
        return;
    }
    int[] indexGroup=new int[2];
    int length=numbs.length;
    if(numbs[0]>target){
        return;
    }
    if((numbs[length-1]+numbs[length-2])<target){
        return;
    }
    int i=0;
    int j=length-1;
    while (i<j){
        if((numbs[i]+numbs[j])<target){
            i++;
            continue;
        }
        if(numbs[i]+numbs[j]>target){
            j--;
            continue;
        }
        if(numbs[i]+numbs[j]==target){
            break;
        }
    }
}





}
