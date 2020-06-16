package com.jdbc.example;

public class C{
	
	private static int findStringIndex(String haystack,String needle) {
		char[] needFindChar = needle.toCharArray();
		int target = -1;
		if (needle == null || needle.equals("")) {
			return 0;
		}
		for (int i = 0; i <= haystack.length() - needFindChar.length; i++) {
			if (haystack.charAt(i) != needFindChar[0]) {
				while (++i <= haystack.length() && haystack.charAt(i)!=needFindChar[0]);
			}
			if (i<haystack.length()) {
				int j = i+1;
				int end = j + needFindChar.length-1;
				for(int k = 1;j<end && haystack.charAt(j) == needFindChar[k];k++,j++);
				if (j == end) {
					return i;
				}
			}
		}
		
		return target;
	}
	
	public static void main(String[] args) {
		System.out.println(findStringIndex("main", "in"));
	}
}
