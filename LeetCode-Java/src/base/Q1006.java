package base;

/**
 * Project: LeetCode-Java
 * File: Q1006
 *
 * @author evan
 * @date 2021/4/1
 */
public class Q1006 {
    private int calculate(int n) {
        if (n >= 3) {
            return n * (n - 1) / (n - 2);
        } else if (n == 2) {
            return n * (n - 1);
        } else if (n == 1) {
            return n;
        } else {
            return 0;
        }
    }

    public int clumsy(int N) {
        int result = 0;
        if (N >= 4) {
            result = calculate(N) + (N - 3);
            N -= 4;
        } else {
            return calculate(N);
        }
        while (N >= 4) {
            result = result - calculate(N) + (N - 3);
            N -= 4;
        }
        return result - calculate(N);
    }

    public static void main(String[] args) {
        Q1006 q = new Q1006();
        System.out.println(q.clumsy(1));
    }
}
