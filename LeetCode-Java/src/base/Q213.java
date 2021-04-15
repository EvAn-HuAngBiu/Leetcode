package base;

/**
 * Project: LeetCode-Java
 * File: Q213
 *
 * @author evan
 * @date 2021/4/15
 */
public class Q213 {
    public int rob(int[] nums) {
        // int len = nums.length;
        // if (len == 1) {
        //     return nums[0];
        // } else if (len == 2) {
        //     return Math.max(nums[0], nums[1]);
        // }
        //
        // int[] dp = new int[len + 1];
        // dp[0] = 0;
        // dp[1] = nums[0];
        // dp[2] = Math.max(nums[0], nums[1]);
        //
        // for (int i = 3; i <= len; ++i) {
        //     dp[i] = Math.max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        // }
        //
        // return Math.max(dp[len] - dp[1], dp[len - 1]);
        int len = nums.length;
        if (len == 1) {
            return nums[0];
        } else if (len == 2) {
            return Math.max(nums[0], nums[1]);
        }
        return Math.max(dp(nums, 0, len - 2), dp(nums, 1, len - 1));
    }

    private int dp(int[] nums, int beg, int end) {
        int len = end - beg + 1;
        if (len == 1) {
            return nums[beg];
        } else if (len == 2) {
            return Math.max(nums[beg], nums[beg + 1]);
        }
        int pre2 = nums[beg], pre1 = Math.max(nums[beg], nums[beg + 1]), cur;
        for (int i = beg + 2; i <= end; ++i) {
            cur = Math.max(pre2 + nums[i], pre1);
            pre2 = pre1;
            pre1 = cur;
        }
        return pre1;
    }

    public static void main(String[] args) {
        Q213 q = new Q213();
        int[] array = {1,2,1,1};
        System.out.println(q.rob(array));
    }
}
