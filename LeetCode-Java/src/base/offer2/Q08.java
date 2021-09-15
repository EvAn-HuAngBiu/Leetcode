package base.offer2;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q08
 *
 * @author evan
 * @date 2021/9/15
 */
public class Q08 {
    public static int minSubArrayLen(int target, int[] nums) {
        int len = nums.length;
        int[] sum = new int[len + 1];
        for (int i = 1; i <= len; ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        int p = 0, q = 1, diff, minLen = Integer.MAX_VALUE;
        while (p < q) {
            diff = sum[q] - sum[p];
            if (diff >= target) {
                minLen = Math.min(minLen, q - p);
            }

            if (diff >= target || q == len) {
                ++p;
                continue;
            }
            ++q;
        }

        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }

    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5};
        System.out.println(minSubArrayLen(11, array));
    }
}
