package base.offer2;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q09
 *
 * @author evan
 * @date 2021/9/15
 */
public class Q09 {
    public static int numSubarrayProductLessThanK(int[] nums, int k) {
        // int p = 0, q = 1, len = nums.length, result = 0, overlap = 0;
        // if (len == 0) {
        //     return 0;
        // }
        // int sum = nums[0];
        // while (p < q) {
        //     sum *= nums[q];
        //     if (sum < k) {
        //         if (q == len - 1) {
        //             return result + ((q - p + 2) * (q - p + 1) >> 1) - overlap;
        //         }
        //     } else {
        //         int diff = q - p + 1;
        //         result += ((1 + diff) * diff >> 1) - 1;
        //         sum /= nums[p++];
        //         diff = q - p + 1;
        //         overlap = ((1 + diff) * diff >> 1);
        //     }
        //     ++q;
        // }
        //
        // return result;
        int len = nums.length;
        if (len == 0) {
            return 0;
        }
        int sum = 1, result = 0, l = 0;
        for (int r = 0; r < len; ++r) {
            sum *= nums[r];
            while (l <= r && sum >= k) {
                sum /= nums[l];
                ++l;
            }
            if (l <= r) {
                result += r - l + 1;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3};
        System.out.println(numSubarrayProductLessThanK(nums, 0));
    }
}
