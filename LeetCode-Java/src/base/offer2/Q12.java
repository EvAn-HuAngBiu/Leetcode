package base.offer2;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q12
 *
 * @author evan
 * @date 2021/9/16
 */
public class Q12 {
    public static int pivotIndex(int[] nums) {
        int len = nums.length;
        int[] sum = new int[len + 1];
        for (int i = 1; i <= len; ++i) {
            sum[i] = nums[i - 1] + sum[i - 1];
        }
        for (int i = 1; i <= len; ++i) {
            if (sum[i - 1] == sum[len] - sum[i]) {
                return i - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] array = {1, 2, 3};
        System.out.println(pivotIndex(array));
    }
}
