package interview.vip;

import java.util.Arrays;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q03
 *
 * @author evan
 * @date 2021/9/15
 */
public class Q03 {
    public static int maxProfit (int[] prices) {
        // int len = prices.length;
        // int maxValue = 0;
        //
        // for (int i = 0; i < len; ++i) {
        //     for (int j = i + 1; j < len; ++j) {
        //         maxValue = Math.max(maxValue, prices[j] - prices[i]);
        //     }
        // }
        //
        // return maxValue;
        int len = prices.length;
        int[][] dp = new int[len][2];
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < len; ++i) {
            dp[i][0] = Math.max(dp[i - 1][0], -prices[i]);
            dp[i][1] = Math.max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[len - 1][1];

        // int len = prices.size();
        // if (len == 0) return 0;
        // vector<vector<int>> dp(len, vector<int>(2));
        // dp[0][0] -= prices[0];
        // dp[0][1] = 0;
        // for (int i = 1; i < len; i++) {
        //     dp[i][0] = max(dp[i - 1][0], -prices[i]);
        //     dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        // }
        // return dp[len - 1][1];

    }

    public static void main(String[] args) {
        int[] array = {3, 2, 1};
        System.out.println(maxProfit(array));
    }
}
