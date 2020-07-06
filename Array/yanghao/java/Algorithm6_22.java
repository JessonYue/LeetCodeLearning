package jdbc.mvc.interfaces;

import java.util.ArrayList;
import java.util.List;

public class Algorithm6_22 {

	public int arrayNesting(int[] nums) {
		int i = 0;
		int res = 0;
		while (i < nums.length) {
			int b = nums[i],c = 0;
			do {
				b = nums[b];
				c++;
			} while (b != nums[i]);
			i++;
			res = Math.max(res, c);
		}
		return res;
    }
	
	public static void main(String[] args) {
		new Algorithm6_22().arrayNesting(new int[]{5,4,0,3,1,6,2});
	}
}
