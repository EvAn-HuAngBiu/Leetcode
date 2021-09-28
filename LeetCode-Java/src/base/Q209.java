package base;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q209
 *
 * @author evan
 * @date 2021/9/28
 */
public class Q209 {
    public static int minSubArrayLen(int target, int[] nums) {
        int minLen = Integer.MAX_VALUE;
        int p = 0, q = 0, len = nums.length, sum = 0;
        while (q <= len) {
            if (sum >= target) {
                while (sum - nums[p] >= target) {
                    sum -= nums[p++];
                }
                minLen = Math.min(minLen, q - p);
                sum -= nums[p++];
            } else if (q < len) {
                sum += nums[q++];
            } else {
                break;
            }
        }

        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }

    public static void main(String[] args) {
        int[] array = {1,1,1,1,1,1,1,1};
        System.out.println(minSubArrayLen(11, array));
    }
}
