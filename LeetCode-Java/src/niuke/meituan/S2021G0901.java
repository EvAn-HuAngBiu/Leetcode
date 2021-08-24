package niuke.meituan;

import java.io.BufferedInputStream;
import java.util.Scanner;
import java.util.TreeSet;

/**
 * <p>
 * Project: LeetCode-Java
 * File: S2021G0901
 *
 * @author evan
 * @date 2021/8/24
 */
public class S2021G0901 {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        while (in.hasNextInt()) {
            int n, m, a, b;
            n = in.nextInt();
            m = in.nextInt();
            a = in.nextInt();
            b = in.nextInt();
            if (a > b) {
                int temp = a;
                a = b;
                b = temp;
            }

            // 对于已经生产的蛋糕进行排序
            TreeSet<Integer> ts = new TreeSet<>();
            for (int i = 0; i < m; ++i) {
                ts.add(in.nextInt());
            }

            // 因为要买的是最重的和最轻的，所以如果已经生产的蛋糕有更重的或更轻的，那么直接失败
            if (ts.first() < a || ts.last() > b) {
                System.out.println("NO");
                continue;
            }
            int need = 2;
            // 如果已经生产的包含最重的，那么需要的个数-1
            if (ts.contains(a)) {
                --need;
            }
            // 如果已经生产的包含最轻的，那么需要的个数-1
            if (ts.contains(b)) {
                --need;
            }
            // 最后只要判断还要生产的够不够需要的即可
            if (need == 0 || need <= n - m) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
