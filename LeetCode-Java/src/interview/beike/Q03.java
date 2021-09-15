package interview.beike;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q03
 *
 * @author evan
 * @date 2021/8/13
 */
public class Q03 {
    public static long section(int[] a, int t) {
        long cnt = 0;
        int len = a.length;
        byte[][] dp = new byte[len][len];
        int[] xor = new int[len];
        for (int i = 0; i < len; ++i) {
            dp[i][i] = 2;
            xor[i] = (a[i] ^ t);
        }
        for (int l = 1; l < len; ++l) {
            for (int i = 0; i < len - l; ++i) {
                int j = i + l;
                if (dp[i][j] != 0 || dp[i + 1][j] == 1 || dp[i][j - 1] == 1) {
                    dp[i][j] = 1;
                    Arrays.fill(dp[i], j, len, ((byte) 1));
                    continue;
                }
                if (xor[i] != a[j]) {
                    dp[i][j] = 2;
                    ++cnt;
                } else {
                    Arrays.fill(dp[i], j, len, (byte)1);
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args) {
        int[] a = {2, 3, 4, 5};
        System.out.println(section(a, 7));
    }
}
