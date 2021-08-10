/**
 * Project: LeetCode-Java
 * File: Q413
 *
 * @author evan
 * @date 2021/8/10
 */
public class Q413 {
    public static int numberOfArithmeticSlices(int[] nums) {
        int len = nums.length;
        if (len < 3) {
            return 0;
        }
        int pre = 0;
        int sum = 0;
        for (int i = 2; i < len; ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                sum += ++pre;
            } else {
                pre = 0;
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println(numberOfArithmeticSlices(new int[]{1, 2, 3, 4}));
    }
}
