package base.offer2;

import java.util.Arrays;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q03
 *
 * @author evan
 * @date 2021/9/14
 */
public class Q03 {
    // public static int[] countBits(int n) {
    //     int bits = 32 - Integer.numberOfLeadingZeros(n);
    //     int[] result = new int[(1 << bits)];
    //     int cur;
    //     for (int i = 1; i <= bits; ++i) {
    //         cur = 0;
    //         for (int j = 0; j < i; ++j) {
    //             cur = (cur << 1) | 1;
    //         }
    //         for (int j = 0; j <= bits - i; ++j) {
    //             result[cur] = i;
    //             cur <<= 1;
    //         }
    //     }
    //     return Arrays.copyOfRange(result, 0, n + 1);
    // }

    public static int[] countBits(int n) {
        if (n == 0) {
            return new int[] {0};
        }
        int[] result = new int[n + 1];
        result[0] = 0;
        result[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (i % 2 == 0) {
                result[i] = result[i / 2];
            } else {
                result[i] = result[i / 2] + 1;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] result = countBits(5);
        System.out.println(Arrays.toString(result));
    }
}
