package day67_0806_leetcode693;

public class day67_leetcode693 {
    public static void main(String[] args) {

        System.out.println(day67_leetcode693.hasAlternatingBits(7));
        System.out.println(day67_leetcode693.hasAlternatingBits2(7));
    }

    // 16 8 4 2 1
    // 1  a

    public static boolean hasAlternatingBits(int n) {
        if (n == 0)
            return false;
        String s = Integer.toBinaryString(n);
        for (int i = 0; i < s.length(); i++) {
            if(i+1 < s.length()){
                char c = s.charAt(i);
                char c1 = s.charAt(i + 1);
                if(c == c1)
                    return false;
                else
                    continue;
            }
        }
        return true;
    }

    //101
    //5   5/2=2  5%2=1       2/2=1    2%2=0     1/2=0    1%2=1   true
    //7   7/2=3  7%2=1       3/2=1    3%2=1     1/2=0    1%2=1
    public static boolean hasAlternatingBits2(int n) {
//       int num1 = n % 2;
//       int num2 = n / 2;
//       while (num2 > 1)
//           num1 = num2 % 2;
//           num2 = num2 / 2;
//       if (num1 == num2)
//           return true;
//       return false;
        int pre = n & 1;
        n >>>= 1;
        while(n != 0){
            if((n & 1) == pre)
                return false;
            pre = n & 1;
            n >>>= 1;
        }
        return true;
    }

    //5   101 &  1     101
    //10 &  1    10
}
