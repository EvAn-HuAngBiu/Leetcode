package base;

/**
 * Project: LeetCode-Java
 * File: Q5730
 *
 * @author evan
 * @date 2021/5/1
 */
public class Q1844 {
    public String replaceDigits(String s) {
        StringBuilder result = new StringBuilder();
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if ((i & 1) == 1) {
                result.append((char)(s.charAt(i - 1) + s.charAt(i) - '0'));
            } else {
                result.append(s.charAt(i));
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        Q1844 q = new Q1844();
        System.out.println(q.replaceDigits("a1c1e1"));
    }
}
