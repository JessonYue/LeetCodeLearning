#include <stdio.h>
#include <string.h>

int strStr(char *haystack, char *needle) {
	if(NULL == haystack || NULL == needle) {
		return 0;
	}
	int i;
	int hay_length = strlen(haystack);
	int needle_length = strlen(needle);
	for(int i=0;i < hay_length - needle_length + 1;i++) {
		if(memcmp(&haystack[i], needle, needle_length) == 0) {
			return i;
		}
	}
	return -1;
}

int main() {
	printf("%d", strStr("abcd", "d"));
	return 0;
}


