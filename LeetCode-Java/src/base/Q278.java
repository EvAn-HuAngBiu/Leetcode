package base;

/**
 * Project: LeetCode-Java
 * File: Q278
 *
 * @author evan
 * @date 2021/3/22
 */
class VersionControl {
    boolean isBadVersion(int version) {
        return true;
    }
}

public class Q278 extends VersionControl {
    public int firstBadVersion(int n) {
        int beg = 1, end = n, mid;
        while (beg < end) {
            mid = beg + (end - beg) / 2;
            if (isBadVersion(mid)) {
                end = mid;
            } else {
                beg = mid + 1;
            }
        }
        return beg;
    }

    public static void main(String[] args) {

    }
}
