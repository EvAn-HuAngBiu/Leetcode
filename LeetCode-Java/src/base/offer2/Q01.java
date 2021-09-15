package base.offer2;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q01
 *
 * @author evan
 * @date 2021/9/14
 */
public class Q01 {
    public static int divide(int a, int b) {
        if (a == 0) {
            return 0;
        } else if (b == 1) {
            return a;
        } else if (a == Integer.MIN_VALUE && b == -1) {
            return Integer.MAX_VALUE;
        }
        boolean positive = (a < 0 && b < 0) || (a > 0 && b > 0);
        a = Math.abs(a);
        b = Math.abs(b);

        int time = 0;
        while (a - b >= 0) {
            a -= b;
            ++time;
        }

        return time * (positive ? 1 : -1);
    }

    public static int divide2(int a, int b) {
        if (a == 0) {
            return 0;
        } else if (b == 1) {
            return a;
        } else if (a == Integer.MIN_VALUE && b == -1) {
            return Integer.MAX_VALUE;
        }
        boolean positive = (a < 0 && b < 0) || (a > 0 && b > 0);
        long la = Math.abs(((long) a));
        long lb = Math.abs(((long) b));

        int shift = 31, result = 0;
        while (la >= lb) {
            while (la < (lb<< shift)) {
                --shift;
            }
            la -= (lb<< shift);
            result += (1 << shift);
        }
        return positive ? result : -result;
    }

    public static void main(String[] args) {
        System.out.println(divide2(-2147483648, 2));
    }
}
