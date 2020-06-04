import java.util.Scanner;

public class Homework_003 {

    // 实现 strStr() 函数，LeetCode第28题
    public void homework_003_028() {
        int resultCode = -1;
        String haystack, needle;
        System.out.print("请输入字符串 haystack ：");
        Scanner scanner = new Scanner(System.in);
        haystack = scanner.nextLine();
        System.out.print("请输入字符串 needle ：");
        needle = scanner.nextLine();
        System.out.println(String.format("字符串 haystack 为：%s\n字符串 needle 为：%s", haystack, needle));
        resultCode = strStr(haystack, needle);
        if(resultCode == -1)
            System.out.println("字符串 haystack 中不存在子字符串 needle");
        else
            System.out.println(String.format("字符串 haystack 中子字符串 needle 所在位置的索引为：%d", resultCode));
    }

    private int strStr(String haystack, String needle) {
        // 通过查看 indexOf 源码，发现，我自己写的查找小串算法比他多循环了 needle 的长度次，并且，发现有 bug 了。。。
        // 例如，大串：bbbaaac，小串：aac，我记录的大串位置到了ac的a位置，所以肯定扫不出小串，好吧，重写一遍
        int sourcelen = haystack.length(), targetlen = needle.length(), maxLoop = sourcelen - targetlen;
        if (sourcelen == 0 || sourcelen < targetlen) {
            return -1;
        }
        if (targetlen == 0) {
            return 0;
        }
        char[] source = haystack.toCharArray(), target = needle.toCharArray();
        int targetFirst, j, end;
        for (int i = 0; i <= maxLoop; i++) {
            targetFirst = 0;
            if (source[i] != target[targetFirst]) {
                // 过滤了前面不匹配的字符
                while (++i <= maxLoop && source[i] != target[targetFirst]);
            }
            if (i <= maxLoop) {
                // 因为经过上面的过滤，第一个字符肯定是相同的，这里匹配第二个开始的就可以了
                // 当扫描的长度等于了目标串长就停止扫描
                end = i + targetlen;
                for (targetFirst++, j = i + 1; j < end && source[j] == target[targetFirst]; j++, targetFirst++);
                if (j == end) {
                    return i;
                }
            }
        }
        return -1;
    }
}
