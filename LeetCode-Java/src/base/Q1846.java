package base;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q5732
 *
 * @author evan
 * @date 2021/5/1
 */
public class Q1846 {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);
        arr[0] = 1;
        int max = 1, len = arr.length;
        for (int i = 1; i < len; ++i) {
            if (Math.abs(arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }
            max = arr[i];
        }
        return max;
    }
}
