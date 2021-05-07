package base;

/**
 * Project: LeetCode-Java
 * File: Q1486
 *
 * @author evan
 * @date 2021/5/7
 */
public class Q1486 {
    public static int xorOperation(int n, int start) {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result ^= (start + 2 * i);
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(xorOperation(5, 0));
    }
}
