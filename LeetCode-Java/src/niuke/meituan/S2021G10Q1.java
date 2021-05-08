package niuke.meituan;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Project: LeetCode-Java
 * File: S2021G10Q1
 *
 * @author evan
 * @date 2021/5/7
 */
public class S2021G10Q1 {
    public static int getScore() {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), x = in.nextInt(), y = in.nextInt();
        List<Integer> scores = new ArrayList<>(n);
        for (int i = 0; i < n; ++i) {
            scores.add(in.nextInt());
        }
        scores.sort(Integer::compareTo);

        for (int i = x; i <= y; ++i) {
            if (n - i >= x && n - i <= y) {
                return scores.get(i - 1);
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(getScore());
    }
}
