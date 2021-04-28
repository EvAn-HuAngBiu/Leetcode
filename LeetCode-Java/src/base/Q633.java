package base;

/**
 * Project: LeetCode-Java
 * File: Q633
 *
 * @author evan
 * @date 2021/4/28
 */
public class Q633 {
    /**
     * 复杂度 O(nlogn), 外层线性查找，内层二分查找
     */
    public boolean judgeSquareSum(int c) {
        int max = (int) Math.sqrt(c);
        for (int i = 0; i <= max; ++i) {
            // TLE
            // for (int j = 0; j <= max; ++j) {
            //     if (i * i + j * j == c) {
            //         return true;
            //     }
            // }
            int beg = 0, end = max, mid, sum;
            while (beg <= end) {
                mid = (beg + end) >> 1;
                sum = i * i + mid * mid;
                if (sum == c) {
                    return true;
                } else if (sum > c) {
                    end = mid - 1;
                } else {
                    beg = mid + 1;
                }
            }
        }
        return false;
    }

    public boolean judgeSquareSum2(int c) {
        int a = 0, b = (int) Math.sqrt(c), sum;
        while (a <= b) {
            sum = a * a + b * b;
            if (sum == c) {
                return true;
            } else if (sum > c) {
                --b;
            } else {
                ++a;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Q633 q = new Q633();
        System.out.println(q.judgeSquareSum2(5));
    }
}
