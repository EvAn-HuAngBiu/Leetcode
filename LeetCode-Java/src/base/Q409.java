package base;

/**
 * Project: LeetCode-Java
 * File: Q409
 *
 * @author evan
 * @date 2021/7/28
 */
public class Q409 {
    public static int longestPalindrome(String s) {
        int[] count = new int[52];
        for (int i = 0; i < s.length(); ++i) {
            char cur = s.charAt(i);
            if (cur >= 'a' && cur <= 'z') {
                count[cur - 'a']++;
            } else {
                count[cur - 'A' + 26]++;
            }
        }
        int even = 0;
        boolean hasOdd = false;
        for (int i = 0; i < 52; ++i) {
            if (count[i] > 0) {
                if (count[i] % 2 == 0) {
                    even += count[i];
                } else {
                    even += count[i] - 1;
                    hasOdd = true;
                }
            }
        }
        return even + (hasOdd ? 1 : 0);
    }

    public static void main(String[] args) {
        System.out.println(longestPalindrome("abcccccdd"));
    }
}
