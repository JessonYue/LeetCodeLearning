package com.example.bsdiff;

import java.util.Stack;

/**
 * ���� S �� T �����ַ����������Ƿֱ����뵽�հ׵��ı��༭�����ж϶����Ƿ���ȣ������ؽ���� # �����˸��ַ���

	ע�⣺����Կ��ı������˸��ַ����ı�����Ϊ�ա�

	ʾ�� 1��

		���룺S = "ab#c", T = "ad#c"
		�����true
		���ͣ�S �� T ������ ��ac����

	ʾ�� 2��

		���룺S = "ab##", T = "c#d#"
		�����true
		���ͣ�S �� T ������ ������
		
	ʾ�� 3��

	���룺S = "a##c", T = "#a#c"
	�����true
	���ͣ�S �� T ������ ��c����
	
	ʾ�� 4��

	���룺S = "a#c", T = "b"
	�����false
	���ͣ�S ���� ��c������ T ��Ȼ�� ��b����
 * @author yanghao
 *
 */
public class Algorithm7_16 {

	public boolean backspaceCompare(String S, String T) {
        return build(S).equals(build(T));
    }

    public String build(String S) {
        Stack<Character> ans = new Stack();
        for (char c: S.toCharArray()) {
            if (c != '#')
                ans.push(c);
            else if (!ans.empty())
                ans.pop();
        }
        return String.valueOf(ans);
    }

}
