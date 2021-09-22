package base.offer2;

import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q15
 *
 * @author evan
 * @date 2021/9/22
 */
public class Q15 {
    public static List<Integer> findAnagrams(String s, String s1) {
        int subLen = s1.length(), len = s.length();
        if (subLen == 0 || subLen > len) {
            return Collections.emptyList();
        }

        List<Integer> result = new LinkedList<>();
        int[] cnt = new int[26];
        for (int i = 0; i < subLen; ++i) {
            cnt[s1.charAt(i) - 'a']++;
        }

        char[] array = s.toCharArray();
        int[] cur = new int[26];
        for (int i = 0; i < subLen; ++i) {
            cur[array[i] - 'a']++;
        }

        int p = 0;
        while (p <= len - subLen) {
            if (Arrays.compare(cnt, cur) == 0) {
                result.add(p);
            }
            cur[array[p] - 'a']--;
            if (p + subLen < len) {
                cur[array[p + subLen] - 'a']++;
            }
            ++p;
        }
        return result;
    }

    public static void main(String[] args) {
        String s2 = "cbaebabacd", s1 = "abc";
        // String s2 = "abab", s1 = "ab";
        System.out.println(findAnagrams(s2, s1));
    }
}
