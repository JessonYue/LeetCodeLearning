package jdbc.mvp;

import java.util.ArrayList;
import java.util.List;

public class Algorithm6_28{

	public int maxProfit(int[] prices) {
		if (prices == null || prices.length == 0) {
            return 0;
        }
        int len = prices.length;

        int min = prices[0];            
        int max = prices[len - 1];      

        int maxPro1 = 0;               
        int maxPro2 = 0;              

        int[] profit1 = new int[len];   
        int[] profit2 = new int[len];  

        for (int i = 0; i < len; i++) {

            if (prices[i] <= min) {
                min = prices[i];
            } else {
                maxPro1 = Math.max(maxPro1, prices[i] - min);
            }
            profit1[i] = maxPro1;

            if (prices[len - 1 - i] >= max) {
                max = prices[len - 1 - i];
            } else {
                maxPro2 = Math.max(maxPro2, max - prices[len - 1 - i]);
            }
            profit2[len - i - 1] = maxPro2;
        }

        int res = Integer.MIN_VALUE;
        for (int i = 0; i < len; i++) {
            res = Math.max(res, profit1[i] + profit2[i]);
        }
        return res;
    }
	
	public static void main(String[] args) {
		System.out.println(new Algorithm6_28().maxProfit(new int[] {1,2,4,2,5,7,2,4,9,0}));
	}
}
