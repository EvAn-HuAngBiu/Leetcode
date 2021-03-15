package base;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q59
 *
 * @author evan
 * @date 2021/3/16
 */
public class Q59 {
    private int generate(int[][] mat, int curNum, int begin, int nCnt) {
        int x = begin, y = begin;
        for (int i = 0; i < nCnt; i++) {
            mat[x][y + i] = curNum++;
        }
        for (int i = 1; i < nCnt; i++) {
            mat[x + i][y + nCnt - 1] = curNum++;
        }
        for (int i = 1; i < nCnt; i++) {
            mat[x + nCnt - 1][y + nCnt - 1 - i] = curNum++;
        }
        for (int i = 1; i < nCnt - 1; i++) {
            mat[x + nCnt - 1 - i][y] = curNum++;
        }
        return curNum;
    }

    public int[][] generateMatrix(int n) {
        if (n == 1) {
            return new int[][]{{1}};
        }
        int[][] mat = new int[n][n];
        int curNum = 1, begin = 0, nCnt = n;
        while (begin < n - 1) {
            curNum = generate(mat, curNum, begin++, nCnt);
            nCnt -= 2;
        }
        return mat;
    }

    public static void main(String[] args) {
        Q59 q = new Q59();
        int[][] ints = q.generateMatrix(1);
        System.out.println(Arrays.deepToString(ints));
    }
}
