package base;

import java.util.LinkedList;

/**
 * Project: LeetCode-Java
 * File: Q1190
 *
 * @author evan
 * @date 2021/5/26
 */
public class Q1190 {
    public static String reverseParentheses(String s) {
        LinkedList<String> list = new LinkedList<>();
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            char cur = s.charAt(i);
            if (cur != ')') {
                list.push(String.valueOf(cur));
            } else {
                StringBuilder sb = new StringBuilder();
                String last;
                while (!"(".equals(last = list.pop())) {
                    sb.append(new StringBuilder(last).reverse().toString());
                }
                list.push(sb.toString());
            }
        }
        StringBuilder result = new StringBuilder();
        while (!list.isEmpty()) {
            result.append(list.pollLast());
        }
        return result.toString();
    }

    public static void main(String[] args) {
        System.out.println(reverseParentheses("(ed(et(oc))el)"));
    }
}
