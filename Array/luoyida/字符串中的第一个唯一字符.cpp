//
// Created by xing on 2020/7/17.
//
int firstUniqChar(char *s) {
    int flag[26] = {0};
    int len = strlen(s);
    int i;
    //第一遍统计各字符出现次数
    for (i = 0; i < len; i++) {
        flag[s[i] - 'a']++;
    }
    //第二遍找到第一个值为1的索引
    for (i = 0; i < len; i++) {
        if (flag[s[i] - 'a'] == 1) return i;
    }
    return -1;

}
/**
 * java数字转换为十六进制数
 */
private

static String intToHex(int n) {
    StringBuffer s = new StringBuffer();
    String a;
    char[]
    b = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (n != 0) {
        s = s.append(b[n % 16]);
        n = n / 16;
    }
    a = s.reverse().toString();
    return a;
}

void moveZeroes(int *nums, int numsSize) {
    int m = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            m++;
        } else if (m > 0) {
            nums[i - m] = nums[i];
            nums[i] = 0;
        }
    }
}

