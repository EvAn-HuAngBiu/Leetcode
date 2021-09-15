package interview.beike;

import java.util.TreeSet;

/**
 * Project: LeetCode-Java
 * File: qo2
 *
 * @author evan
 * @date 2021/8/13
 */
public class Q02 {
    public static String NS_String (String s, int k) {
        // write code here
        TreeSet<Character> ts = new TreeSet<>();
        for (int i = 0; i < s.length(); ++i) {
            ts.add(s.charAt(i));
        }
        for (int i = 0; i < k; ++i) {
            ts.pollFirst();
        }
        char[] str = new char[s.length()];
        int idx = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (ts.contains(c)) {
                str[idx++] = c;
            }
        }
        return new String(str, 0, idx);
    }

    public static void main(String[] args) {
        System.out.println(NS_String("cbcb", 2));
    }
}
