package base;

import java.util.Objects;

/**
 * Project: LeetCode-Java
 * File: Q363
 *
 * @author evan
 * @date 2021/4/22
 */
public class Q363 {

    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;
        int max = Integer.MIN_VALUE;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int[][] dp = new int[m + 1][n + 1];
                dp[i][j] = matrix[i - 1][j - 1];

                for (int p = i; p <= m; ++p) {
                    for (int q = j; q <= n; ++q) {
                        dp[p][q] = dp[p - 1][q] + dp[p][q - 1] - dp[p - 1][q - 1] + matrix[p - 1][q - 1];
                        if (dp[p][q] <= k && dp[p][q] > max) {
                            max = dp[p][q];
                        }
                    }
                }
            }
        }
        return max;
    }

    public static void main(String[] args) {
        int[][] arr = {{2, 2, -1}};
        Q363 q = new Q363();
        System.out.println(q.maxSumSubmatrix(arr, 0));
    }
}
