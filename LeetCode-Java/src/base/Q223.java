package base;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q223
 *
 * @author evan
 * @date 2021/10/9
 */
public class Q223 {
    private int calcOverlap(int a1, int a2, int b1, int b2) {
        int aLeft = Math.min(a1, a2), aRight = Math.max(a1, a2);
        int bLeft = Math.min(b1, b2), bRight = Math.max(b1, b2);

        int aL = Math.min(aLeft, bLeft), aR = (aL == aLeft ? aRight : bRight);
        int bL = (aL == aLeft ? bLeft : aLeft), bR = (bL == bLeft ? bRight : aRight);

        if (bL > aR || bR < aL) {
            return 0;
        } else if (bL >= aL && bR <= aR) {
            return bR - bL;
        }
        return aR - bL;
    }

    public int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int aArea = (Math.max(ax1, ax2) - Math.min(ax1, ax2)) *
                (Math.max(ay1, ay2) - Math.min(ay1, ay2));
        int bArea = (Math.max(bx1, bx2) - Math.min(bx1, bx2)) *
                (Math.max(by1, by2) - Math.min(by1, by2));
        return aArea + bArea - calcOverlap(ax1, ax2, bx1, bx2) * calcOverlap(ay1, ay2, by1, by2);
    }

    public static void main(String[] args) {
        System.out.println(new Q223().
                computeArea(-5, -3, 0, 5, -3, -3, 3, 3));
    }
}
