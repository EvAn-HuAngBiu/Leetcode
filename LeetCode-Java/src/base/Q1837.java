package base;

/**
 * Project: LeetCode-Java
 * File: Q1837
 *
 * @author evan
 * @date 2021/4/28
 */
public class Q1837 {
    public int sumBase(int n, int k) {
        int sum = 0;
        while (n != 0) {
            sum += n % k;
            n /= k;
        }
        return sum;
    }

    public static void main(String[] args) {
        Q1837 q = new Q1837();
        System.out.println(q.sumBase(10, 10));
    }
}
