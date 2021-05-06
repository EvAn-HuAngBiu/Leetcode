package base;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Project: LeetCode-Java
 * File: Q403
 *
 * @author evan
 * @date 2021/4/29
 */
public class Q403 {
    private Boolean[][] record;

    private boolean loop(int[] stones, int index, int k) {
        if (index == stones.length - 1) {
            return true;
        }
        if (record[index][k] != null) {
            return record[index][k];
        }
        for (int i = k - 1; i <= k + 1; ++i) {
            if (i > 0) {
                int search = Arrays.binarySearch(stones, index + 1, stones.length, stones[index] + i);
                if (search >= 0 && loop(stones, search, i)) {
                    record[index][k] = true;
                    return true;
                }
            }
        }
        record[index][k] = false;
        return false;
    }

    public boolean canCross(int[] stones) {
        record = new Boolean[stones.length][stones.length];
        return loop(stones, 0, 0);
    }

    public static boolean canCrossDP(int[] stones) {
        int len = stones.length;
        boolean[][] dp = new boolean[len][len];
        dp[0][0] = true;
        for (int  i = 1; i < len; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int k = stones[i] - stones[j];
                if (k > j + 1) {
                    break;
                }
                dp[i][k] = dp[j][k] || dp[j][k - 1] || dp[j][k + 1];
            }
        }
        for (int i = 0; i < len; ++i) {
            if (dp[len - 1][i]) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[] arr = {0,1,3,5,6,8,12,17};
        System.out.println(canCrossDP(arr));
    }
}
