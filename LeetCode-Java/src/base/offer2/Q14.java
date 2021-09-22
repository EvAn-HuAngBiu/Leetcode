package base.offer2;

import java.util.Arrays;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q14
 *
 * @author evan
 * @date 2021/9/22
 */
public class Q14 {
    public static boolean checkInclusion(String s1, String s2) {
        int subLen = s1.length(), len = s2.length();
        if (subLen == 0) {
            return true;
        } else if (subLen > len) {
            return false;
        }

        int[] cnt = new int[26];
        for (int i = 0; i < subLen; ++i) {
            cnt[s1.charAt(i) - 'a']++;
        }

        char[] array = s2.toCharArray();
        int[] cur = new int[26];
        for (int i = 0; i < subLen; ++i) {
            cur[array[i] - 'a']++;
        }

        if (Arrays.compare(cnt, cur) == 0) {
            return true;
        }

        int p = 0;
        while (p < len - subLen) {
            cur[array[p] - 'a']--;
            cur[array[p + subLen] - 'a']++;
            if (Arrays.compare(cnt, cur) == 0) {
                return true;
            }
            ++p;
        }

        return false;
    }

    public static void main(String[] args) {
        String s1 = "ab";
        String s2 = "eidboaoo";
        System.out.println(checkInclusion(s1, s2));
    }
}
