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

    // 两数相加，LeetCode第2题
    // 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    // 输出：7 -> 0 -> 8
    void homework_003_002() {
        Scanner scanner = new Scanner(System.in);
        int num1, num2;
        System.out.print("请输入第一个正整数：");
        num1 = scanner.nextInt();
        System.out.print("请输入第二个正整数：");
        num2 = scanner.nextInt();
        System.out.println(String.format("输入的表达式为：%d + %d = %d", num1, num2, num1 + num2));
        System.out.println("倒叙的表达式为：");
        ListNode list1 = reversalNum(num1);
        ListNode list2 = reversalNum(num2);
        System.out.print("(");
        displayList(list1);
        System.out.print(") + (");
        displayList(list2);
        System.out.println(")");
        ListNode list = addTwoNumbers(list1, list2);
        displayList(list);
        System.out.print("\n");
    }

    // 987999 + 876 = 7641
    private ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode mergeList = new ListNode((l1.val + l2.val) % 10), list1 = l1.next, list2 = l2.next, prior = mergeList, next = null;
        int sum = l1.val + l2.val, bit = 10;
        while (list1 != null && list2 != null) {
            sum += (list1.val + list2.val) * bit;
            next = new ListNode((sum / bit) % 10);
            prior.next = next;
            prior = next;
            bit *= 10;
            list1 = list1.next;
            list2 = list2.next;
        }
        while (list1 != null) {
            sum += list1.val * bit;
            next = new ListNode((sum / bit) % 10);
            prior.next = next;
            prior = next;

            bit *= 10;
            list1 = list1.next;
        }
        while (list2 != null) {
            sum += list2.val * bit;
            next = new ListNode((sum / bit) % 10);
            prior.next = next;
            prior = next;

            bit *= 10;
            list2 = list2.next;
        }
        if (sum / bit != 0) {   // 最后一位有进位
            next = new ListNode(sum / bit);
            prior.next = next;
            prior = next;
        }
        return mergeList;
    }

    // 将数据反转
    private ListNode reversalNum(int num) {
        ListNode head;
        if (num < 10) {
            head = new ListNode(num);
        } else {
            int result = num / 10;
            head = new ListNode(num % 10);  // 取最后一位
            ListNode prior = head, next;
            while (result != 0) {
                next = new ListNode(result % 10);   // 取最后一位
                prior.next = next;
                prior = next;
                result /= 10;   // 去除最后一位
            }
        }
        return head;
    }

    // 打印信息，格式为：1 —> 2 —> 3 —> 4
    private void displayList(ListNode list) {
        ListNode temp = list;
        while (temp.next != null) {
            System.out.print(temp.val + " —> ");
            temp = temp.next;
        }
        System.out.print(temp.val);
    }
}
