package interview.beike;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q01
 *
 * @author evan
 * @date 2021/8/13
 */
public class Q01 {
    public static void main(String[] args) {
        System.out.println(Arrays.toString(test(10, ((long) 500))));
    }

    public static long[] FarmerNN (int n, long m) {
        // write code here
        long[] result = new long[n];
        int idx = 0, delta = 1;
        while (m > 0) {
            if (idx == n) {
                idx = n - 2;
                delta = -1;
            } else if (idx <= 0 && delta == -1) {
                idx = 0;
                delta = 1;
            }
            result[idx]++;
            idx += delta;
            --m;
        }
        return result;
    }

    public static long[] test(int n, long m) {
        long times = m / (n + n - 2);
        long[] result = new long[n];
        Arrays.fill(result, times * 2);
        result[0] = result[n - 1] = times;
        long last = m - times * (n + n - 2);
        int idx = 0, delta = 1;
        while (last > 0) {
            if (idx == n) {
                idx = n - 2;
                delta = -1;
            } else if (idx <= 0 && delta == -1) {
                idx = 0;
                delta = 1;
            }
            result[idx]++;
            idx += delta;
            --last;
        }
        return result;
    }
}
