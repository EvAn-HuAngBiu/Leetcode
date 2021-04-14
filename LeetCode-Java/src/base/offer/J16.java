package base.offer;

/**
 * Project: LeetCode-Java
 * File: J16
 *
 * @author evan
 * @date 2021/4/14
 */
public class J16 {
    public double myPow(double x, int n) {
        boolean neg = false;
        long b = n;
        if (n < 0) {
            neg = true;
            b = -b;
        }
        double result = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                result *= x;
            }
            x *= x;
            b >>= 1;
        }
        if (neg) {
            return 1 / result;
        }
        return result;
    }

    public static void main(String[] args) {
        J16 j = new J16();
        System.out.println(j.myPow(2.00000, -2147483648));
    }
}
