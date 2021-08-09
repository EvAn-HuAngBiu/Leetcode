package base;

/**
 * Project: LeetCode-Java
 * File: Q1925
 *
 * @author evan
 * @date 2021/8/9
 */
public class Q1925 {
    public static int countTriples(int n) {
        int cnt = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = a + 1; b <= n; ++b) {
                int result = a * a + b * b, sq = (int)Math.sqrt(result);
                if (sq <= n && sq * sq == result) {
                    cnt += 2;
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args) {
        System.out.println(countTriples(18));
    }
}
