package base;

import java.util.Arrays;
import java.util.stream.Stream;

/**
 * Project: LeetCode-Java
 * File: Q389
 *
 * @author evan
 * @date 2021/6/23
 */
public class Q389 {
    public static char findTheDifference(String s, String t) {
        int[] pos = new int[26];
        s.chars().forEach(c -> pos[c - 'a']++);
        t.chars().forEach(c -> pos[c - 'a']--);
        for (int i = 0; i < 26; ++i) {
            if (pos[i] < 0) {
                return (char)(i + 'a');
            }
        }
        return '\0';
    }

    public static void main(String[] args) {
        System.out.println(findTheDifference("ab", "aba"));
    }
}
