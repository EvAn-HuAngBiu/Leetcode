package base.offer2;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q20
 *
 * @author evan
 * @date 2021/9/25
 */
public class Q20 {
    public static int countSubstrings(String s) {
        int len = s.length();
        boolean[][] dp = new boolean[len][len];
        for (int i = 0; i < len; ++i) {
            dp[i][i] = true;
        }
        int cnt = len;
        for (int i = 2; i <= len; ++i) {
            for (int j = 0; j <= len - i; ++j) {
                int k = j + i - 1;
                boolean b = s.charAt(j) == s.charAt(k);
                if (i == 2) {
                    dp[j][k] = b;
                } else {
                    dp[j][k] = dp[j + 1][k - 1] && b;
                }
                cnt += (dp[j][k] ? 1 : 0);
            }
        }

        return cnt;
    }

    public static void main(String[] args) {
        System.out.println(countSubstrings("abc"));
    }
}
