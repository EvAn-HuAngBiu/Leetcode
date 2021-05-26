package base;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q338
 *
 * @author evan
 * @date 2021/5/26
 */
public class Q338 {
    public static int[] countBits(int n) {
        if (n == 0) {
            return new int[]{0};
        } else if (n == 1) {
            return new int[] {0, 1};
        }
        int[] result = new int[n + 1];
        result[0] = 0;
        result[1] = 1;
        int last = 1;
        for (int i = 2; i <= n; ++i) {
            if (i == 1 << (last + 1)) {
                ++last;
            }
            result[i] = result[i - (1 << last)] + 1;
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(countBits(5)));
    }
}
