package base;

/**
 * Project: LeetCode-Java
 * File: Q53
 *
 * @author evan
 * @date 2021/4/22
 */
public class Q53 {
    public int maxSubArray(int[] nums) {
        int len = nums.length;
        if (len == 1) {
            return nums[0];
        }

        int dp = 0, max = Integer.MIN_VALUE;
        for (int num : nums) {
            if (dp < 0) {
                dp = num;
            } else {
                dp = dp + num;
            }
            max = Math.max(max, dp);
        }
        return max;
    }

    public static void main(String[] args) {
        Q53 q = new Q53();
        System.out.println(q.maxSubArray(new int[]{-2,1,-3,4,-1,2,1,-5,4}));
    }
}
