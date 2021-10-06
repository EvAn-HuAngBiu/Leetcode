package base.offer2;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q32
 *
 * @author evan
 * @date 2021/10/6
 */
public class Q32 {
    public static boolean isAnagram(String s, String t) {
        int[] count = new int[26];
        int lens = s.length(), lent = t.length();
        if (lens != lent) {
            return false;
        }

        boolean eq = true;
        for (int i = 0; i < lens; ++i) {
            count[s.charAt(i) - 'a']++;
            count[t.charAt(i) - 'a']--;
            if (s.charAt(i) != t.charAt(i)) {
                eq = false;
            }
        }
        if (eq) {
            return false;
        }

        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(isAnagram("a", "a"));
    }
}
