package base;

/**
 * Project: LeetCode-Java
 * File: Q115
 *
 * @author evan
 * @date 2021/3/17
 */
public class Q115 {
    public int numDistinct(String s, String t) {
        int m = s.length(), n = t.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }

    public static void main(String[] args) {
        Q115 q = new Q115();
        System.out.println(q.numDistinct("babgbag", "bag"));
    }
}
