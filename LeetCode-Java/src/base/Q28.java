package base;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q28
 *
 * @author evan
 * @date 2021/4/20
 */
public class Q28 {
    private int[] next;

    void calNext(char[] pattern) {
        next[0] = -1;
        int k = -1, j = 0;
        while (j < pattern.length - 1) {
            if (k == -1 || pattern[j] == pattern[k]) {
                next[++j] = ++k;
            } else {
                k = next[k];
            }
        }
    }

    public int strStr(String haystack, String needle) {
        int hLength = haystack.length(), nLength = needle.length();
        if (nLength == 0) {
            return 0;
        }
        next = new int[nLength];
        this.calNext(needle.toCharArray());

        int i = 0, j = 0;
        while (i < hLength && j < nLength) {
            if (j == -1 || haystack.charAt(i) == needle.charAt(j)) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }
        if (j >= nLength) {
            return i - nLength;
        }
        return -1;
    }

    public static void main(String[] args) {
        Q28 q = new Q28();
        System.out.println(q.strStr("", "a"));
    }
}
