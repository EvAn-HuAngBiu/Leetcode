package base;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q377
 *
 * @author evan
 * @date 2021/4/24
 */
public class Q377 {
    private int count = 0;

    // TLE
    private void dfs(int[] nums, int target, int sum) {
        if (sum == target) {
            ++count;
        } else if (sum > target) {
            return;
        }
        for (int num : nums) {
            dfs(nums, target, sum + num);
        }
    }

    public int combinationSum4(int[] nums, int target) {
        // DP
        int[] dp = new int[target + 1];
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (num == i) {
                    ++dp[i];
                } else if (num < i) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }

    public static void main(String[] args) {
        Q377 q = new Q377();
        System.out.println(q.combinationSum4(new int[]{1, 2, 3}, 4));
    }
}
