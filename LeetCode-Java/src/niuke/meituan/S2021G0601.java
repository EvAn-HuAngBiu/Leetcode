package niuke.meituan;

import java.util.Scanner;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0601
 *
 * @author evan
 * @date 2021/8/27
 */
public class S2021G0601 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; ++i) {
            array[i] = in.nextInt();
        }
        int idx = 0;
        while (array[idx] < k) {
            ++idx;
        }
        int count = 0, total = 0;
        for (int i = idx; i < n; ++i) {
            if (array[i] >= k) {
                ++count;
            } else {
                if (count >= m) {
                    total += count - m + 1;
                }
                count = 0;
            }
        }
        if (count >= m) {
            total += count - m + 1;
        }
        System.out.println(total);
    }
}
