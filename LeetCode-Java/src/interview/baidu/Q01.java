package interview.baidu;

import java.util.Arrays;
import java.util.Scanner;

public class Q01 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), k = in.nextInt();

        int[][] original = new int[n][n];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                original[i][j] = in.nextInt();
            }
        }

        int sum = n * k;
        int[][] result = new int[sum][sum];
        int cx = 0, cy = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int m = 0; m < k; ++m) {
                    // for (int p = 0; p < k; ++p) {
                    //     result[cx + m][cy + p] = original[i][j];
                    // }
                    Arrays.fill(result[cx + m], cy, cy + k, original[i][j]);
                }
                cx += k;
            }
            cx = 0;
            cy += k;
        }

        for (int i = 0; i < sum; ++i) {
            for (int j = 0; j < sum; ++j) {
                if (j != 0) {
                    System.out.print(" ");
                }
                System.out.printf("%d", result[i][j]);
            }
            System.out.println();
        }
    }
}
