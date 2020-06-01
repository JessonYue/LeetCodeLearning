public class Solution_06_02 {
public static void main(String [] args){
    System.out.print(climbStairs(5)+"");
}
    public static int climbStairs(int n) {
        if (n > 0) {
            if (n == 1) return 1;
            if (n == 2) return 2;
            return climbStairs(n - 1) + climbStairs(n - 2);
        } else {
            return 0;
        }
    }
}
