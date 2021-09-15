package interview.tencent;

import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeMap;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q2
 *
 * @author evan
 * @date 2021/9/5
 */
public class Q2 {
    private static int[] factors = new int[100001];

    public static void getFactors(int n) {
        if (n == 1) {
            factors[1] = 1;
            return;
        }
        for (int i = 1; i <= n / 2; ++i) {
            if (n % i == 0 && i != 1) {
                factors[n] += factors[n / i];
                break;
            }
        }
        if (factors[n] == 0) {
            factors[n] = 1;
        }
        factors[n] += 1;
    }

    public static void main(String[] args) {
        for (int i = 1; i <= 10; ++i) {
            getFactors(i);
        }

        System.out.println(Arrays.toString(Arrays.copyOfRange(factors, 0, 11)));
        // Scanner in = new Scanner(System.in);
        // int n = in.nextInt(), f, b;
        // int[] a = new int[n];
        // TreeMap<Integer, Integer> va = new TreeMap<>();
        // for (int i = 0; i < n; ++i) {
        //     a[i] = in.nextInt();
        //     va.put(facs[a[i]], va.getOrDefault(facs[a[i]], 0) + 1);
        // }
        //
        // int cnt = 0;
        // for (int i = 0; i < n; ++i) {
        //     b = in.nextInt();
        //     Integer k = va.higherKey(facs[b]);
        //     if (k != null) {
        //         int val = va.get(k);
        //         if (val > 0) {
        //             va.put(k, va.get(k) - 1);
        //         } else {
        //             va.remove(k);
        //         }
        //         ++cnt;
        //     }
        // }
        //
        // System.out.println(cnt);
    }
}
