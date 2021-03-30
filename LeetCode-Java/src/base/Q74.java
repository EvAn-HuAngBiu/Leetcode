package base;

/**
 * Project: LeetCode-Java
 * File: Q74
 *
 * @author evan
 * @date 2021/3/30
 */
public class Q74 {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        if (m == 0) {
            return false;
        }
        int n = matrix[0].length;

        // 列二分查找
        int beg = 0, end = m * n - 1, mid;
        while (beg <= end) {
            mid = (beg + end) / 2;
            int x = mid / n, y = mid % n;
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] > target) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        int[][] matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
        // int[][] matrix = {{1}};
        Q74 q = new Q74();
        System.out.println(q.searchMatrix(matrix, 16));
    }
}
