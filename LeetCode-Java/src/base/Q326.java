package base;

/**
 * Project: LeetCode-Java
 * File: Q326
 *
 * @author evan
 * @date 2021/3/26
 */
public class Q326 {
    public boolean isPowerOfThree(int n) {
        return Math.log10(n) / Math.log10(3) % 1 == 0;
    }

    public static void main(String[] args) {
        Q326 q = new Q326();
        System.out.println(q.isPowerOfThree(243));
    }
}
