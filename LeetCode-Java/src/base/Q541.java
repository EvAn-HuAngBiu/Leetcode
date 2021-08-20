package base;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q541
 *
 * @author evan
 * @date 2021/8/20
 */
public class Q541 {
    public static String reverseStr(String s, int k) {
        char[] chars = s.toCharArray();
        int len = chars.length;
        char[] result = new char[len];
        int idx = 0, ptr = 0;
        while (idx < len) {
            int last = Math.min((idx + k - 1), len - 1);
            while (last >= idx) {
                result[ptr++] = chars[last--];
            }
            if ((idx = Math.min((idx + k), len)) == len) {
                break;
            }
            for (int i = 0; i < Math.min(k, len - idx); ++i) {
                result[ptr++] = chars[idx + i];
            }
            idx += k;
        }

        return new String(result);
    }

    public static void main(String[] args) {
        System.out.println(reverseStr("abcdef", 2));
    }
}
