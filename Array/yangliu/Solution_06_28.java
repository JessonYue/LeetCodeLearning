public class Solution_06_28 {


    public  static void  main(String []arg){
        int [] ints={3,3,5,0,0,3,1,4};
        maxProfit(ints);
    }
    public static int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        int len = prices.length;

        int min = prices[0];
        int max = prices[len - 1];

        int maxP = 0;
        int maxL = 0;

        int[] profitP = new int[len];
        int[] profitL = new int[len];

        for (int i = 0; i < len; i++) {


            if (prices[i] <= min) {
                min = prices[i];
            } else {
                maxP = Math.max(maxP, prices[i] - min);
            }
            profitP[i] = maxP;


            if (prices[len - 1 - i] >= max) {
                max = prices[len - 1 - i];
            } else {
                maxL = Math.max(maxL, max - prices[len - 1 - i]);
            }
            profitL[len - i - 1] = maxL;
        }


        int res = 0;
        for (int i = 0; i < len; i++) {
            res = Math.max(res, profitP[i] + profitL[i]);
        }
        return res;
    }


}
