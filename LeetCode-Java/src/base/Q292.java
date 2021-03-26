package base;

/**
 * Project: LeetCode-Java
 * File: Q292
 *
 * @author evan
 * @date 2021/3/26
 */
public class Q292 {

    // TLE
    public boolean canWinNim(int n) {
        boolean isWin0 = true, isWin1 = true, isWin2 = true;
        for (int i = 3; i < n; i++) {
            boolean cur = !isWin0 || !isWin1 || !isWin2;
            isWin0 = isWin1;
            isWin1 = isWin2;
            isWin2 = cur;
        }
        return isWin2;
    }

    public boolean canWinNim2(int n) {
        return n % 4 != 0;
    }

    public static void main(String[] args) {
        Q292 q = new Q292();
        System.out.println(q.canWinNim(Integer.MAX_VALUE));
    }
}
