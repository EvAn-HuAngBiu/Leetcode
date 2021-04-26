package base;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q1011
 *
 * @author evan
 * @date 2021/4/26
 */
public class Q1011 {
    public int shipWithinDays(int[] weights, int D) {
        int left = Arrays.stream(weights).max().getAsInt(), right = Arrays.stream(weights).sum();
        while (left < right) {
            int mid = left + right << 1;
            int time = 1;
            int sum = 0;
            for (int w : weights) {
                if (w + sum > mid) {
                    ++time;
                    sum = w;
                } else {
                    sum += w;
                }
            }
            if (time > D) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
