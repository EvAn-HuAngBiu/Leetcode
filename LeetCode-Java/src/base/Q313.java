package base;

/**
 * Project: LeetCode-Java
 * File: Q313
 *
 * @author evan
 * @date 2021/8/9
 */
public class Q313 {
    public static int nthSuperUglyNumber(int n, int[] primes) {
        if (n == 1) {
            return 1;
        }
        int len = primes.length;
        int[] result = new int[n];
        result[0] = 1;
        int[] cnt = new int[len];
        for (int i = 1; i < n; ++i) {
            int min = Integer.MAX_VALUE;
            for (int j = 0; j < len; ++j) {
                int tmp = primes[j] * result[cnt[j]];
                if (tmp < min && tmp > result[i - 1]) {
                    min = tmp;
                }
            }
            for (int j = 0; j < len; ++j) {
                if (primes[j] * result[cnt[j]] == min) {
                    ++cnt[j];
                }
            }
            result[i] = min;
        }
        return result[n - 1];
    }

    public static void main(String[] args) {
        System.out.println(nthSuperUglyNumber(15, new int[]{3, 5, 7, 11, 19, 23, 29, 41, 43, 47}));
    }
}
