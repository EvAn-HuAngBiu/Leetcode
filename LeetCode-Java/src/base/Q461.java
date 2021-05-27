package base;

/**
 * Project: LeetCode-Java
 * File: Q461
 *
 * @author evan
 * @date 2021/5/27
 */
public class Q461 {
    public static int hammingDistance(int x, int y) {
        int result = x ^ y;
        int cnt = 0;
        while (result != 0) {
            if ((result & 1) == 1) {
                ++cnt;
            }
            result >>= 1;
        }
        return cnt;
    }

    public static void main(String[] args) {
        System.out.println(hammingDistance(1, 4));
    }
}
