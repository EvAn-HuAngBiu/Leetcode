package base;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q283
 *
 * @author evan
 * @date 2021/3/23
 */
public class Q283 {
    public void moveZeroes(int[] nums) {
        int len = nums.length;
        int p = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] != 0) {
                nums[p++] = nums[i];
            }
        }
        for (int i = p; i < len; i++) {
            nums[i] = 0;
        }
    }

    public static void main(String[] args) {
        int[] nums = {0, 1, 0, 3, 12};
        Q283 q = new Q283();
        q.moveZeroes(nums);
        System.out.println(Arrays.toString(nums));
    }
}
