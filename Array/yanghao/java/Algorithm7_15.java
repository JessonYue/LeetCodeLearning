package com.example.bsdiff;

/**
 * ����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
 * ʾ��:

		����: [0,1,0,3,12]
		���: [1,3,12,0,0]
 * 
 * @author yanghao
 *
 */
public class Algorithm7_15 {

	public void moveZeroes(int[] nums) {
		if(nums==null) {
			return;
		}
		int j = 0;
		for(int i=0;i<nums.length;++i) {
			if(nums[i]!=0) {
				nums[j++] = nums[i];
			}
		}
		for(int i=j;i<nums.length;++i) {
			nums[i] = 0;
		}
	}

}
