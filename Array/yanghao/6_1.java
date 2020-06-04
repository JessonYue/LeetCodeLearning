package com.jdbc.example;

public class B {

	/**
	 * 2020.06.1 167. ����֮�� II - ������������ ����һ���Ѱ����������� ���������飬�ҵ�������ʹ���������֮�͵���Ŀ������
	 * 
	 * ����Ӧ�÷����������±�ֵ index1 �� index2������ index1 ����С�� index2��
	 * 
	 * ˵��:
	 * 
	 * ���ص��±�ֵ��index1 �� index2�����Ǵ��㿪ʼ�ġ� ����Լ���ÿ������ֻ��ӦΨһ�Ĵ𰸣������㲻�����ظ�ʹ����ͬ��Ԫ�ء� ʾ��:
	 * 
	 * ����: numbers = [2, 7, 11, 15], target = 9 ���: [1,2] ����: 2 �� 7 ֮�͵���Ŀ���� 9 �����
	 * index1 = 1, index2 = 2 ��
	 * 
	 * @param num
	 * @param target
	 * @return
	 */
	public static int[] findSum(int[] num, int target) {
		int[] index = { -1, 1 };
		int low = 0;
		int high = num.length - 1;
		while (low < high) {
			int sum = num[high] + num[low];
			if (sum == target) {
				index[0] = low + 1;
				index[1] = high + 1;
				return index;
			} else if (sum < target) {
				++low;
			} else {
				--high;
			}
		}

		return index;
	}

	public static void main(String[] args) {
		findSum(new int[] { 1, 2, 3, 4 }, 5);
	}
}
