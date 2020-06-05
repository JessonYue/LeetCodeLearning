package com.jdbc.example;

public class D {

	 public void merge(int []a,int left,int mid,int right){
	        int []tmp=new int[a.length];
	        int p1=left,p2=mid+1,k=left;

	        while(p1<=mid && p2<=right){
	            if(a[p1]<=a[p2])
	                tmp[k++]=a[p1++];
	            else
	                tmp[k++]=a[p2++];
	        }

	        while(p1<=mid) tmp[k++]=a[p1++];
	        while(p2<=right) tmp[k++]=a[p2++];

	        
	        for (int i = left; i <=right; i++) 
	            a[i]=tmp[i];
	    }

	    public void mergeSort(int [] a,int start,int end){
	        if(start<end){
	            int mid=(start+end)/2;
	            mergeSort(a, start, mid);
	            mergeSort(a, mid+1, end);
	            merge(a, start, mid, end);
	        }
	    }
	    
	    public static void margeArray(int [] a,int[] b) {
			for (int i = a.length-b.length; i < a.length; i++) {
				a[i] = b[i+b.length-a.length];
			}
			
			new D().mergeSort(a, 0, a.length-1);
		}
	    
	    public static void main(String[] args) {
	    	int[] a = {1,2,4,8,10,0,0,0};
	    	int[] b = {3,5,9};
			margeArray(a, b);
			for (int i = 0; i < a.length; i++) {
				System.out.println(a[i]);
			}
		}
}
