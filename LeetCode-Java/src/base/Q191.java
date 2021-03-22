package base;

/**
 * Project: LeetCode-Java
 * File: Q191
 *
 * @author evan
 * @date 2021/3/22
 */
public class Q191 {
    public int hammingWeight(int n) {
        int cnt = 0, total = 0;
        while (total < 32) {
            cnt += (n & 1);
            n >>= 1;
            ++total;
        }
        return cnt;
    }

    public static void main(String[] args) {
        Q191 q = new Q191();
        System.out.println(q.hammingWeight(-3));
    }
}
