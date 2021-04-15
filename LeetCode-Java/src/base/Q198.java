package base;

/**
 * Project: LeetCode-Java
 * File: Q198
 *
 * @author evan
 * @date 2021/4/15
 */
public class Q198 {
    public int rob(int[] nums) {
        int len = nums.length;
        if (len == 1) {
            return nums[0];
        } else if (len == 2) {
            return Math.max(nums[0], nums[1]);
        }

        int pre2 = nums[0], pre1 = Math.max(nums[0], nums[1]), cur;

        for (int i = 3; i <= len; ++i) {
            cur = Math.max(pre2 + nums[i - 1], pre1);
            pre2 = pre1;
            pre1 = cur;
        }
        return pre1;
    }

    public static void main(String[] args) {
        Q198 q = new Q198();
        int[] arr = {2, 7, 9, 3, 1};
        System.out.println(q.rob(arr));
    }
}
