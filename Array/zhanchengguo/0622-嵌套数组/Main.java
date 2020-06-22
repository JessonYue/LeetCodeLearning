import android.util.Log;

public class Main {

    void main() {
        int a[] = {5,4,0,3,1,6,2};
        int result = arrayNesting(a);
        Log.w("result is ", result + "");
    }

    public int arrayNesting(int[] nums) {
        boolean[] visited = new boolean[nums.length];
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            if (!visited[i]) {
                int start = nums[i], count = 0;
                do {
                    start = nums[start];
                    count++;
                    visited[start] = true;
                }
                while (start != nums[i]);
                res = Math.max(res, count);
            }
        }
        return res;
    }
}

