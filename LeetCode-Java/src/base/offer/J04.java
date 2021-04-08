package base.offer;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: J04
 *
 * @author evan
 * @date 2021/4/7
 */
public class J04 {
    // 错解：试图用二分查找，先找行再找列的想法，
    // 错误原因：见main函数的测试用例
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        int m = matrix.length;
        if (m == 0) {
            return false;
        }
        int n = matrix[0].length;
        if (n == 0) {
            return false;
        }

        int index = Arrays.binarySearch(matrix[0], target);
        if (index >= 0) {
            return true;
        }
        index = -index - 2;
        if (index < 0) {
            return false;
        }
        int beg = 0, end = m - 1, mid;
        while (beg <= end) {
            mid = (beg + end) / 2;
            if (matrix[mid][index] == target) {
                return true;
            } else if (matrix[mid][index] > target) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }

        return false;
    }

    public boolean findNumberIn2DArray2(int[][] matrix, int target) {
        int m = matrix.length;
        if (m == 0) {
            return false;
        }
        int n = matrix[0].length;
        int p = m - 1, q = 0;
        while (p >= 0 && q <= n - 1) {
            if (matrix[p][q] == target) {
                return true;
            } else if (matrix[p][q] > target) {
                --p;
            } else {
                ++q;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        J04 j = new J04();
        int[][] matrix = {
                {1, 2, 3, 4, 5},
                {6, 7, 8, 9, 10},
                {11, 12, 13, 14, 15},
                {16, 17, 18, 19, 20},
                {21, 22, 23, 24, 25}
        };

        System.out.println(j.findNumberIn2DArray2(matrix, 19));
    }
}
