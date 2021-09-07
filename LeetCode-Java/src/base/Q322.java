package base;

import java.util.Arrays;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q322
 *
 * @author evan
 * @date 2021/9/6
 */
public class Q322 {
    private static final int INF = Integer.MAX_VALUE - 5;

    public static int coinChange(int[] coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        Arrays.sort(coins);
        int len = coins.length;
        int[][] dp = new int[len + 1][amount + 1];
        for (int i = 0; i <= len; ++i) {
            Arrays.fill(dp[i], INF);
            dp[i][0] = 0;
        }

        int k = 1, sum;
        while ((sum = k * coins[0]) <= amount) {
            dp[1][sum] = k;
            ++k;
        }

        for (int i = 2; i <= len; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (j < coins[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                }
            }
        }

        return dp[len][amount] == INF ? -1 : dp[len][amount];
    }

    public static void main(String[] args) {
        System.out.println(coinChange(new int[]{1}, 2));
    }
}
