package base;

import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * Project: LeetCode-Java
 * File: Q1738
 *
 * @author evan
 * @date 2021/5/19
 */
public class Q1738 {
    public static int kthLargestValue(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;
        PriorityQueue<Integer> heap = new PriorityQueue<>(Comparator.reverseOrder());
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                } else if (i == 0) {
                    matrix[i][j] = matrix[i][j - 1] ^ matrix[i][j];
                } else if (j == 0) {
                    matrix[i][j] = matrix[i - 1][j] ^ matrix[i][j];
                } else {
                    matrix[i][j] ^= matrix[i - 1][j - 1] ^ matrix[i - 1][j] ^ matrix[i][j - 1];
                }
                heap.add(matrix[i][j]);
            }
        }
        for (int i = 0; i < k - 1; ++i) {
            heap.poll();
        }
        return heap.peek();
    }

    public static void main(String[] args) {
        int[][] matrix = {{5, 2}, {1, 6}};
        System.out.println(kthLargestValue(matrix, 4));
    }
}
