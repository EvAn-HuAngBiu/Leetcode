package base;

import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeSet;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q239
 *
 * @author evan
 * @date 2021/9/28
 */
public class Q239 {
    public static int[] maxSlidingWindow(int[] nums, int k) {
        int len = nums.length;
        int[] result = new int[len - k + 1];
        int q = 0;
        for (int i = 1; i < k; ++i) {
            if (nums[i] >= nums[q]) {
                q = i;
            }
        }

        for (int p = 0; p < len - k + 1; ++p) {
            if (p > q) {
                q = p;
                for (int j = 0; j < k; ++j) {
                    if (nums[j + p] >= nums[q]) {
                        q = j + p;
                    }
                }
            }
            result[p] = nums[q];
            if (k > 1 && p + k < len) {
                if (nums[p + k] >= nums[q]) {
                    q = p + k;
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int[] nums = {9,10,9,-7,-4,-8,2,-6};
        System.out.println(Arrays.toString(maxSlidingWindow(nums, 5)));
    }
}
