package base;

/**
 * Project: LeetCode-Java
 * File: Q374
 *
 * @author evan
 * @date 2021/4/1
 */
public class Q374 {
    private int pick = 2;

    private int guess(int num) {
        if (num == pick) {
            return 0;
        } else if (num > pick) {
            return -1;
        } else {
            return 1;
        }
    }

    public int guessNumber(int n) {
        int beg = 0, end = n, mid = 0, result;
        while (beg <= end) {
            mid = beg + (end - beg) / 2;
            result = guess(mid);
            if (result == 0) {
                return mid;
            } else if (result == 1) {
                beg = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return mid;
    }

    public static void main(String[] args) {
        Q374 q = new Q374();
        System.out.println(q.guessNumber(2));
    }
}
