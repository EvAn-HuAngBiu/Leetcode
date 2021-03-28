package base;

/**
 * Project: LeetCode-Java
 * File: Q342
 *
 * @author evan
 * @date 2021/3/28
 */
public class Q342 {
    public boolean isPowerOfFour(int n) {
        return Math.log10(n) / Math.log10(4) % 1 == 0;
    }

    public static void main(String[] args) {
        Q342 q = new Q342();
        System.out.println(q.isPowerOfFour(1));
    }
}
