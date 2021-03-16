package base;

/**
 * Project: LeetCode-Java
 * File: Q231
 *
 * @author evan
 * @date 2021/3/16
 */
public class Q231 {
    // TLE
    public boolean isPowerOfTwo(int n) {
        int result = 1;
        while (result < n) {
            result = result * 2;
        }
        return result == n;
    }

    public boolean isPowerOfTwo2(int n) {
        if (n <= 0) {
            return false;
        }
        int cnt = 0;
        for (int i = 0; i < 31; i++) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt == 1;
    }

    public static void main(String[] args) {
        Q231 q = new Q231();
        System.out.println(q.isPowerOfTwo2(-2147483645));
    }
}
