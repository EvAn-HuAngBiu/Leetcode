package base;

/**
 * Project: LeetCode-Java
 * File: Q516
 *
 * @author evan
 * @date 2021/8/13
 */
public class Q516 {
    public static int longestPalindromeSubseq(String s) {
        int len = s.length();
        int[][] dp = new int[len][len];
        for (int i = 0; i < len; ++i) {
            dp[i][i] = 1;
        }
        int maxLen = 0;
        for (int l = 1; l < len; ++l) {
            for (int i = 0; i < len - l; ++i) {
                int j = i + l;
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                }
                maxLen = Math.max(maxLen, dp[i][j]);
            }
        }
        return maxLen;
    }

    public static void main(String[] args) {
        System.out.println(longestPalindromeSubseq("abcd"));
    }
}
