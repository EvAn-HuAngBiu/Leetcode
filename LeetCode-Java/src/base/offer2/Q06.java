package base.offer2;

import java.util.Arrays;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q06
 *
 * @author evan
 * @date 2021/9/15
 */
public class Q06 {
    public static int[] twoSum(int[] numbers, int target) {
        int len = numbers.length;
        for (int i = 0; i < len; ++i) {
            int idx = Arrays.binarySearch(numbers, i + 1, len, target - numbers[i]);
            if (idx > 0) {
                return new int[] {i, idx};
            }
        }
        return null;
    }

    public static void main(String[] args) {
        int[] numbers = {1, 2, 4, 6, 10};
        System.out.println(Arrays.toString(twoSum(numbers, 8)));
    }
}
