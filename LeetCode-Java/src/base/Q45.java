package base;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q45
 *
 * @author evan
 * @date 2021/5/28
 */
public class Q45 {
    private int minCount = Integer.MAX_VALUE;

    public void dfs(int[] nums, int idx, int cnt) {
        int last = nums.length - 1;
        if (idx == last) {
            minCount = Integer.min(minCount, cnt);
            return;
        }
        for (int i = 1; i <= nums[idx]; ++i) {
            if (idx + i <= last) {
                dfs(nums, idx + i, cnt + 1);
            }
        }
    }

    public int jump(int[] nums) {
        dfs(nums, 0, 0);
        return minCount;
    }

    public int jumpDP(int[] nums) {
        int len = nums.length;
        int[] dp = new int[len];
        Arrays.fill(dp,Integer.MAX_VALUE);
        dp[0] = 0;
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] + j >= i) {
                    dp[i] = Integer.min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[len - 1];
    }

    public static void main(String[] args) {
        int[] nums = {2, 3, 0, 1, 4};
        System.out.println(new Q45().jumpDP(nums));
    }
}
