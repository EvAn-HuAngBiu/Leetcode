package base;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q300
 *
 * @author evan
 * @date 2021/8/27
 */
public class Q300 {
    public static int lengthOfLIS(int[] nums) {
        int len = nums.length;
        int[] dp = new int[len];
        int maxLen = 1;
        dp[0] = 1;
        for (int i = 1; i < len; ++i) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] > nums[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                    maxLen = Math.max(dp[i], maxLen);
                }
            }
        }
        return maxLen;
    }

    public static void main(String[] args) {
        System.out.println(lengthOfLIS(new int[] {1,3,6,7,9,4,10,5,6}));
    }
}
