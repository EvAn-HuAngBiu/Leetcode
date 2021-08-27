package niuke.meituan;

import java.util.Scanner;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0602
 *
 * @author evan
 * @date 2021/8/27
 */
public class S2021G0602 {
    private static long total = 0;
    private static long k;
    private static long d;

    private static void dfs(long target, boolean flag) {
        if (!flag && target < d) {
            return;
        }
        if (target == 0) {
            if (flag) {
                total = (total + 1) % 998244353;
            }
            return;
        }
        for (long i = 1; i <= Math.min(target, k); ++i) {
            if (flag) {
                dfs(target - i, true);
            } else {
                dfs(target - i, i >= d);
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        k = in.nextLong();
        d = in.nextLong();
        if (n == 1) {
            System.out.println(1);
            return;
        }

        long[][] dp = new long[n + 1][2];
        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= Math.min(k, i); ++j) {
                if (j < d) {
                    // 对上面DFS的DP，dp[i][0]表示凑成i且没有出现大于d的值的种类数，dp[i][1]表示凑成i且出现大于de的值的种类数
                    // 那么显然如果要知道到当前i没有大于d值的个数，那么要求前面也不能出现，且j要小于d，否则就是出现了
                    // 而j小于d时，如果当前i出现大于d值，那么一定来源于前面
                    dp[i][0] = (dp[i][0] + dp[i - j][0]) % 998244353;
                    dp[i][1] = (dp[i][1] + dp[i - j][1]) % 998244353;
                } else {
                    // 而如果是j大于d时，出现i值既可以来自前面，也可以是当前j（即前面没出现大于d值），所以二者相加即可
                    dp[i][1] = (dp[i][1] + dp[i - j][1] + dp[i - j][0]) % 998244353;
                }
            }
        }

        System.out.println(dp[n][1]);
    }
}
