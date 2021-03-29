package base;

/**
 * Project: LeetCode-Java
 * File: Q190
 *
 * @author evan
 * @date 2021/3/29
 */
public class Q190 {
    private int quickPow(int x, int y) {
        int result = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                result = result * x;
            }
            y /= 2;
            x *= x;
        }
        return result;
    }

    public int reverseBits(int n) {
        int result = 0;
        int cnt = 31;
        while (n != 0) {
            result += (n & 1) * quickPow(2, cnt--);
            n >>>= 1;
        }
        return result;
    }

    public static void main(String[] args) {
        Q190 q = new Q190();
        System.out.println(q.reverseBits(-3));
    }
}
