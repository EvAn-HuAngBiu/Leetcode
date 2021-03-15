package base;

import java.util.ArrayList;
import java.util.List;

/**
 * Project: LeetCode-Java
 * File: Q54
 *
 * @author evan
 * @date 2021/3/15
 */
public class Q54 {
    public List<Integer> loop(int[][] m, int begin, int rCnt, int cCnt) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < cCnt; ++i) {
            result.add(m[begin][i + begin]);
        }
        for (int i = 1; i < rCnt; ++i) {
            result.add(m[begin + i][begin + cCnt - 1]);
        }
        for (int i = cCnt - 2; rCnt > 1 && i > 0; --i) {
            result.add(m[begin + rCnt - 1][i + begin]);
        }
        for (int i = rCnt - 1; cCnt > 1 && i > 0; --i) {
            result.add(m[i + begin][begin]);
        }
        return result;
    }

    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        if (matrix.length == 0) {
            return result;
        }
        int begin = 0, row = matrix.length, column = matrix[0].length;
        while (row > 0 && column > 0) {
            result.addAll(this.loop(matrix, begin++, row, column));
            row -= 2;
            column -= 2;
        }
        return result;
    }

    public static void main(String[] args) {
        // int[][] matrix = {{1,2,3},{4,5,6},{7,8,9}};
        // int[][] matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
        // int[][] matrix = {{1,2},{3,4},{5,6}};
        int[][] matrix = {{7}, {9}, {6}};

        Q54 q = new Q54();
        System.out.println(q.spiralOrder(matrix));
    }
}
