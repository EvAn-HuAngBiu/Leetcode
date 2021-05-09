package niuke.meituan;

import java.util.Arrays;
import java.util.Scanner;

/**
 * Project: LeetCode-Java
 * File: S20210509Q2
 *
 * @author evan
 * @date 2021/5/9
 */
public class S20210509Q2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt(), h = in.nextInt();
        int[] list = new int[n];
        for (int i = 0; i < n; ++i) {
            list[i] = in.nextInt();
        }

        for (int i = 0; i <= n - m; ++i) {
            if (Arrays.stream(list, i, i + m).max().getAsInt() <= h) {
                System.out.println(i + 1);
                return;
            }
        }
        System.out.println(-1);
    }
}
