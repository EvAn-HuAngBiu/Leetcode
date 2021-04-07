package base;

/**
 * Project: LeetCode-Java
 * File: Q81
 *
 * @author evan
 * @date 2021/4/7
 */
public class Q81 {
    public boolean search(int[] nums, int target) {
        int len = nums.length, index = 0;
        if (len == 0) {
            return false;
        }
        for (int i = 0; i < len - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                index = i + 1;
                break;
            }
        }

        int beg = 0, end = len - 1, mid, real;
        while (beg <= end) {
            mid = (beg + end) / 2;
            real = (index + mid) % len;
            if (nums[real] == target) {
                return true;
            } else if (nums[real] > target) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[] arr = {1,1};
        Q81 q = new Q81();
        System.out.println(q.search(arr, 0));
    }
}
