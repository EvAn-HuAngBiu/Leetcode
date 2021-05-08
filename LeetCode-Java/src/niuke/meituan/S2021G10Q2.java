package niuke.meituan;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Project: LeetCode-Java
 * File: S2021G1Q2
 *
 * @author evan
 * @date 2021/5/7
 */
public class S2021G10Q2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cnt = in.nextInt();
        int total = 0;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < cnt; ++i) {
            list.add(in.nextInt());
        }
        list.sort(Integer::compareTo);
        for (int i = 0; i < cnt; ++i) {
            total += Math.abs(i + 1 - list.get(i));
        }
        System.out.println(total);
    }
}
