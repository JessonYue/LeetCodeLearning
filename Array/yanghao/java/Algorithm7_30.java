package bb;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
/**
 * 给定两个数组，编写一个函数来计算它们的交集。
	示例 1：
	输入：nums1 = [1,2,2,1], nums2 = [2,2]
	输出：[2]
	
	示例 2：
	输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
	输出：[9,4]

 * @author yanghao
 *
 */
public class Algorithm7_30{

	public int[] set_intersection(HashSet<Integer> set1, HashSet<Integer> set2) {
	    int [] output = new int[set1.size()];
	    int idx = 0;
	    for (Integer s : set1)
	      if (set2.contains(s)) output[idx++] = s;

	    return Arrays.copyOf(output, idx);
	  }

	  public int[] intersection(int[] nums1, int[] nums2) {
	    HashSet<Integer> set1 = new HashSet<Integer>();
	    for (Integer n : nums1) set1.add(n);
	    HashSet<Integer> set2 = new HashSet<Integer>();
	    for (Integer n : nums2) set2.add(n);

	    if (set1.size() < set2.size()) return set_intersection(set1, set2);
	    else return set_intersection(set2, set1);
	  }


}
