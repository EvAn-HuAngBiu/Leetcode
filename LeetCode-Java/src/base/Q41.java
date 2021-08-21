package base;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q41
 *
 * @author evan
 * @date 2021/8/22
 */
public class Q41 {
    public static int firstMissingPositive(int[] nums) {
        int len = nums.length;
        for (int i = 0; i < len; ++i) {
            if (nums[i] == i + 1) {
                continue;
            }
            while (nums[i] > 0 && nums[i] <= len && nums[i] != nums[nums[i] - 1]) {
                int temp = nums[i];
                nums[i] = nums[temp - 1];
                nums[temp - 1] = temp;
            }
        }

        for (int i = 0; i < len; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return len + 1;
    }

    public static void main(String[] args) {
        System.out.println(firstMissingPositive(new int[]{1, 1}));
    }
}
