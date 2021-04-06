package base;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q80
 *
 * @author evan
 * @date 2021/4/6
 */
public class Q80 {
    public int removeDuplicates(int[] nums) {
        if (nums.length <= 2) {
            return nums.length;
        }
        int p = 1;
        for (int i = 2; i < nums.length; ++i) {
            if (nums[i] == nums[p] && nums[i] == nums[p - 1]) {
                continue;
            }
            nums[++p] = nums[i];
        }
        return p + 1;
    }

    public static void main(String[] args) {
        int[] array = {0,0,1,1,1,1,2,3,3};
        Q80 q = new Q80();
        System.out.println(q.removeDuplicates(array));
        System.out.println(Arrays.toString(array));
    }
}
