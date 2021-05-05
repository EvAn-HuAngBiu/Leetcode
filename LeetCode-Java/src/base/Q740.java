package base;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q740
 *
 * @author evan
 * @date 2021/5/5
 */
public class Q740 {
    public static int deleteAndEarn(int[] nums) {
        int max = Arrays.stream(nums).max().getAsInt();
        int[] sum = new int[max + 1];
        for (int num : nums) {
            ++sum[num];
        }

        int pre2 = 0, pre1 = 0, temp;
        for (int i = 1; i <= max; ++i) {
            temp = Math.max(pre1, pre2 + sum[i] * i);
            pre2 = pre1;
            pre1 = temp;
        }
        return pre1;
    }

    public static void main(String[] args) {
        int[] nums = {3, 4, 2};
        System.out.println(deleteAndEarn(nums));
    }
}
