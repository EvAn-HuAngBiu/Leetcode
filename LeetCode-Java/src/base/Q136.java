package base;

/**
 * Project: LeetCode-Java
 * File: Q136
 *
 * @author evan
 * @date 2021/5/5
 */
public class Q136 {
    public int singleNumber(int[] nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
}
