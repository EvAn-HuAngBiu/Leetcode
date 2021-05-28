package base;

/**
 * Project: LeetCode-Java
 * File: Q477
 *
 * @author evan
 * @date 2021/5/28
 */
public class Q477 {
    public static int totalHammingDistance(int[] nums) {
        int cnt = 0, len = nums.length;
        for (int j = 0; j < 30; ++j) {
            int zero = 0, one = 0;
            for (int i = 0; i < len; ++i) {
                if ((nums[i] & 1) == 1) {
                    ++one;
                } else {
                    ++zero;
                }
                nums[i] >>>= 1;
            }
            cnt += zero * one;
        }
        return cnt;
    }

    public static void main(String[] args) {
        int[] nums = {4, 14, 2, 18};
        System.out.println(totalHammingDistance(nums));
    }
}
