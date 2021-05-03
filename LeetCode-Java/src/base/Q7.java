package base;

/**
 * Project: LeetCode-Java
 * File: Q7
 *
 * @author evan
 * @date 2021/5/3
 */
public class Q7 {
    public static int reverse(int x) {
        long n = 0;
        while (x != 0) {
            n = n * 10 + x % 10;
            x /= 10;
        }
        return (int)n == n ? (int)n : 0;
    }

    public static void main(String[] args) {
        System.out.println(reverse(-123));
    }
}
