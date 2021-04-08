package base;

/**
 * Project: LeetCode-Java
 * File: Q153
 *
 * @author evan
 * @date 2021/4/8
 */
public class Q153 {
    /** 线性查找，时间复杂度O(n) */
    public int findMin(int[] nums) {
        int index = 0, len = nums.length;
        for (int i = 0; i < len - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                index = i + 1;
                break;
            }
        }
        return nums[index];
    }

    /** 二分查找，时间复杂度O(logn) */
    public int findMin2(int[] nums) {
        int beg = 0, end = nums.length - 1, mid;
        while (beg <= end) {
            mid = (beg + end) / 2;
            if (nums[mid] > nums[end]) {
                beg = mid + 1;
            } else {
                end = mid;
            }
        }
        return nums[beg];
    }
}
