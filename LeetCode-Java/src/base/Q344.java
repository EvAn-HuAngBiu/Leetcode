package base;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q344
 *
 * @author evan
 * @date 2021/3/28
 */
public class Q344 {
    public void reverseString(char[] s) {
        int p = 0, q = s.length - 1;
        while (p < q) {
            char temp = s[p];
            s[p] = s[q];
            s[q] = temp;
            ++p;
            --q;
        }
    }

    public static void main(String[] args) {
        char[] str1 = {'h', 'e', 'l', 'l', 'o', 'w'};
        char[] str2 = {'l', 'i', 'n', 'u', 'x'};
        char[] str3 = {};
        Q344 q = new Q344();
        q.reverseString(str3);
        System.out.println(Arrays.toString(str3));
    }
}
