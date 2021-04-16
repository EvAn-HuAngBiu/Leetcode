package niuke.ctrip;

import java.util.Scanner;

/**
 * Project: LeetCode-Java
 * File: S2019Q3
 *
 * @author evan
 * @date 2021/4/15
 */
public class S2019Q3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long num = in.nextLong();
        int cnt = 0;
        while (num != 0) {
            if ((num & 1) == 1) {
                ++cnt;
            }
            num >>>= 1;
        }
        System.out.println(cnt);
    }
}
