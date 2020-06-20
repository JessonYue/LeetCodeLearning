package com.example.admin.myapplication.stack;

import org.mockito.internal.matchers.Null;

import java.util.LinkedList;
import java.util.Queue;

/**
 * create by yx
 * on 2020/6/19
 * 1047. 删除字符串中的所有相邻重复项
 * 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
 * 在 S 上反复执行重复项删除操作，直到无法继续删除。
 * 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
 */
public class SolutionDeleteRepetition {
    public String removeDuplicates(String S) {
        if (S == null || S.isEmpty()) {
            return S;
        }
        Queue<Character> queue = new LinkedList<>();
        for (Character c : S.toCharArray()) {
            queue.add(c);
        }
        return remove(queue);
    }

    private String remove(Queue<Character> queue) {
        boolean isOk = true;
        for (int i = 0, count = queue.size(); i < count; ) {
            Character c = queue.poll();
            i++;
            if (i == count) {
                queue.add(c);
                break;
            }
            if (c.equals(queue.peek())) {
                queue.poll();
                i++;
                isOk = false;
            } else {
                queue.add(c);
            }
        }
        if (isOk) {
            StringBuilder sb = new StringBuilder();
            while (!queue.isEmpty()) {
                sb.append(queue.poll());
            }
            return sb.toString();
        }

        return remove(queue);
    }
}
