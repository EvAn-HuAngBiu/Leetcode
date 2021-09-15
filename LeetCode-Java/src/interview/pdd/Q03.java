package interview.pdd;

import java.io.BufferedInputStream;
import java.util.Scanner;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q03
 *
 * @author evan
 * @date 2021/8/22
 */
public class Q03 {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        long t = in.nextLong();
        for (int i = 0; i < t; ++i) {
            long n = in.nextInt(), m = in.nextInt();
            long beg = ((long) Math.pow(10, n - 1));
            if (beg % m == 0) {
                System.out.println(beg);
            } else {
                long next = m * (beg / m + 1);
                if (next >= Math.pow(10, n)) {
                    System.out.println(-1);
                } else {
                    System.out.println(next);
                }
            }
        }
    }
}
