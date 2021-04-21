package base.offer;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: J21
 *
 * @author evan
 * @date 2021/4/21
 */
public class J21 {
    public int[] exchange(int[] nums) {
         int p = 0, q = nums.length - 1;
         while (p < q) {
             while (p < q && nums[p] % 2 == 1) {
                 ++p;
             }
             while (p < q && nums[q] % 2 == 0) {
                 --q;
             }
             int temp = nums[p];
             nums[p] = nums[q];
             nums[q] = temp;
         }
         return nums;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5};
        System.out.println(Arrays.toString(new J21().exchange(nums)));
    }
}
