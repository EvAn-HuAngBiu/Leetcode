package base;

import java.util.HashSet;
import java.util.Set;

/**
 * Project: LeetCode-Java
 * File: Q367
 *
 * @author evan
 * @date 2021/3/30
 */
public class Q367 {
    public boolean isPerfectSquare(int num) {
        if (num < 2) {
            return true;
        }
        long beg = 0, end = num / 2, mid;
        while (beg <= end) {
            mid = beg + (end - beg) / 2;
            long result = mid * mid;
            if (result == num) {
                return true;
            } else if (result > num) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Q367 q = new Q367();
        System.out.println(q.isPerfectSquare(808201));
    }
}
