package game;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: G1806
 *
 * @author evan
 * @date 2021/3/29
 */
public class G1806 {

    public int reinitializePermutation(int n) {
        int[] perm = new int[n];
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        int[] original = Arrays.copyOf(arr, n);
        int cnt = 0;
        do {
            perm = Arrays.copyOf(arr, n);
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0) {
                    arr[i] = perm[i / 2];
                } else {
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                }
            }
            ++cnt;
        } while (!Arrays.equals(original, arr));
        return cnt;
    }

    public int reinitializePermutation2(int n) {
        int cnt = 0, pos = 1;
        do {
            if (pos % 2 == 0) {
                pos /= 2;
            } else {
                pos = (n + pos - 1) / 2;
            }
            ++cnt;
        } while (pos != 1);
        return cnt;
    }

    public static void main(String[] args) {
        G1806 g = new G1806();
        System.out.println(g.reinitializePermutation2(10));
    }
}
