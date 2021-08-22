package base;

import java.util.*;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q151
 *
 * @author evan
 * @date 2021/8/22
 */
public class Q151 {
    public static String reverseWords(String s) {
        int len = s.length();
        LinkedList<String> result = new LinkedList<>();
        StringBuilder current = new StringBuilder();
        for (int i = 0; i < len; ++i) {
            char cur = s.charAt(i);
            if (cur == ' ') {
                if (current.length() > 0) {
                    result.addFirst(current.toString());
                    current.delete(0, current.length());
                }
            } else {
                current.append(cur);
            }
        }
        if (current.length() > 0) {
            result.addFirst(current.toString());
        }
        current.delete(0, current.length());
        for (String s1 : result) {
            current.append(s1).append(" ");
        }
        current.deleteCharAt(current.length() - 1);
        return current.toString();
    }

    public static void main(String[] args) {
        System.out.println(reverseWords("Alice does not even like bob"));
    }
}
