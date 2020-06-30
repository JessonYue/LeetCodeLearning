public class day29 {

    public static int maxProfit(int prices[], int pricesSize) {
        int dp1 = 0;
        int dp2 = -0xFFFF;
        int dp3 = 0;
        int dp4 = -0xFFFF;
        for (int i = 0; i < pricesSize; i++) {

            dp3 = maxValue(dp3, dp4 + prices[i]);
            dp4 = maxValue(dp4, dp1 - prices[i]);
            dp1 = maxValue(dp1, dp2 + prices[i]);
            dp2 = maxValue(dp2, 0 - prices[i]);
        }

        return dp3;
    }

    public static int maxValue(int dp1, int dp2) {
        if (dp1 > dp2) {
            return dp1;
        } else if (dp2 > dp1) {
            return dp2;
        } else {
            return dp1;
        }
    }

    public static void main(String[] args) {
        int data[] = {3, 3, 5, 0, 0, 3, 1, 4};
        System.out.println("=====" + maxProfit(data, 8));
    }

}
