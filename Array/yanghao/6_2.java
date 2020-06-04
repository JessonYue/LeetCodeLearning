package com.jdbc.example;

public class A {

	/**
	 * 2020.06.2 70. ��¥�� ������������¥�ݡ���Ҫ n ������ܵ���¥����
	 * 
	 * ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
	 * 
	 * ע�⣺���� n ��һ����������
	 * 
	 * ʾ�� 1��
	 * 
	 * ���룺 2 ����� 2 ���ͣ� �����ַ�����������¥���� 1. 1 �� + 1 �� 2. 2 �� ʾ�� 2��
	 * 
	 * ���룺 3 ����� 3 ���ͣ� �����ַ�����������¥���� 1. 1 �� + 1 �� + 1 �� 2. 1 �� + 2 �� 3. 2 �� + 1 ��
	 * 
	 * @param target
	 * @return
	 */
	public int upStairs(int target) {
		return upStairs(0, target);
	}

	public int upStairs(int i, int n) {
		if (i > n) {
			return 0;
		}

		if (i == n) {
			return 1;
		}

		return upStairs(i + 1, n) + upStairs(i + 2, n);
	}

	public static void main(String[] args) {
		new A().upStairs(10);
	}

}
