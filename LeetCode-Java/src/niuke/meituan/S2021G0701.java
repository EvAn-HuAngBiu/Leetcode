package niuke.meituan;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0701
 *
 * @author evan
 * @date 2021/8/26
 */
public class S2021G0701 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt();
        int n = in.nextInt();
        int used = 0;
        int count = 0;

        for (int i = 10; i < 100; ++i) {
            int b1 = i / 10, b2 = i % 10;
            if (b1 == b2) {
                continue;
            }
            used |= (1 << b1);
            used |= (1 << b2);

            for (int j = 0; j < 100; ++j) {
                int c1 = j / 10, c2 = j % 10;
                if (c1 == c2 || (used & (1 << c1)) != 0 || (used & (1 << c2)) != 0) {
                    continue;
                }
                used |= (1 << c1);
                used |= (1 << c2);
                int k = i + j;
                if (k < 100) {
                    int d1 = k / 10, d2 = k % 10;
                    if (d1 != d2 && (used & (1 << d1)) == 0 && (used & (1 << d2)) == 0) {
                        int total = i * 10000 + j * 100 + k;
                        if (total >= m && total <= n) {
                            ++count;
                        }
                    }
                }

                used ^= (1 << c1);
                used ^= (1 << c2);
            }
            used ^= (1 << b1);
            used ^= (1 << b2);
        }
        System.out.println(count);
    }
}
