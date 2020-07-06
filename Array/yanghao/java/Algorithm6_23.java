package jdbc.mvc.interfaces;

import java.util.List;

public class Algorithm6_23 {

	public int findNumbers(int[] nums) {
		int a = 0;
		for (int i = 0; i < nums.length; i++) {
			String c = String.valueOf(nums[i]);
			if (c.length() % 2 == 0) {
				a++;
			}
		}
		return a;
    }
}
