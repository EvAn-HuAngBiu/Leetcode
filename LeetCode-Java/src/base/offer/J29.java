package base.offer;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: J29
 *
 * @author evan
 * @date 2021/4/27
 */
public class J29 {
    private int handleLoop(int[][] matrix, int x, int y, int[] result, int p) {
        int row = matrix.length - x - x, col = matrix[0].length - y - y;
        for (int i = 0; i < col; ++i) {
            result[p++] = matrix[x][i + y];
        }
        for (int i = 1; i < row; ++i) {
            result[p++] = matrix[i + x][y + col - 1];
        }
        for (int i = col - 2; row > 1 && i >= 0; --i) {
            result[p++] = matrix[x + row - 1][i + y];
        }
        for (int i = row - 2; col > 1 && i > 0; --i) {
            result[p++] = matrix[i + x][y];
        }
        return p;
    }

    public int[] spiralOrder(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return new int[0];
        }
        int size = matrix.length * matrix[0].length;
        int[] result = new int[size];
        int p = 0, x = 0, y = 0;
        while (p < size) {
            p = handleLoop(matrix, x, y, result, p);
            ++x;
            ++y;
        }
        return result;
    }

    public static void main(String[] args) {
        int[][] matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        J29 j = new J29();
        System.out.println(Arrays.toString(j.spiralOrder(matrix)));
    }
}
