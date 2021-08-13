package base;

/**
 * Project: LeetCode-Java
 * File: Q5
 *
 * @author evan
 * @date 2021/8/12
 */
public class Q5 {
    public static String longestPalindrome(String s) {
        String maxStr = s.substring(0, 1);
        int len = s.length();
        boolean[][] dp = new boolean[len][len];
        for (int i = 0; i < len; ++i) {
            dp[i][i] = true;
        }
        for (int l = 1; l < len; ++l) {
            for (int i = 0; i < len - l; ++i) {
                int j = i + l;
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = l == 1 || dp[i + 1][j - 1];
                    maxStr = dp[i][j] && maxStr.length() < l + 1 ? s.substring(i, j + 1) : maxStr;
                }
            }
        }
        return maxStr;
    }

    public static void main(String[] args) {
        System.out.println(longestPalindrome("cbbd"));
    }
}
