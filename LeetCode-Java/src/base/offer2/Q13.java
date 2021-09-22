package base.offer2;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q13
 *
 * @author evan
 * @date 2021/9/22
 */
class NumMatrix {
    private int[][] rowSum;

    public NumMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        rowSum = new int[m][n + 1];

        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                rowSum[i][j] = rowSum[i][j - 1] + matrix[i][j - 1];
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        for (int i = row1; i <= row2; ++i) {
            result += rowSum[i][col2 + 1] - rowSum[i][col1];
        }
        return result;
    }
}

public class Q13 {
    public static void main(String[] args) {
        int[][] matrix = {
                {3, 0, 1, 4, 2},
                {5, 6, 3, 2, 1},
                {1, 2, 0, 1, 5},
                {4, 1, 0, 1, 7},
                {1, 0, 3, 0, 5}
        };
        NumMatrix n = new NumMatrix(matrix);

        System.out.println(n.sumRegion(2, 1, 4, 3));
    }
}
