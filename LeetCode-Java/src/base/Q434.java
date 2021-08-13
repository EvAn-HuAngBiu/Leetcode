package base;

/**
 * Project: LeetCode-Java
 * File: Q434
 *
 * @author evan
 * @date 2021/8/13
 */
public class Q434 {
    public static int countSegments(String s) {
        int len = s.length();
        if (len == 0) {
            return 0;
        }
        boolean hasString = false;
        int cnt = 0;
        for (int i = 0; i < len; ++i) {
            char c = s.charAt(i);
            if (c == ' ' && hasString) {
                hasString = false;
                ++cnt;
            } else if (c != ' ') {
                hasString = true;
            }
        }
        return hasString ? cnt + 1 : cnt;
    }

    public static void main(String[] args) {
        System.out.println(countSegments("ab,  c,  d"));
    }
}
