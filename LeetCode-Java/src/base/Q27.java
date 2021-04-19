package base;

/**
 * Project: LeetCode-Java
 * File: Q27
 *
 * @author evan
 * @date 2021/4/19
 */
public class Q27 {
    public int removeElement(int[] nums, int val) {
        int len = nums.length;
        int p = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] != val) {
                nums[p++] = nums[i];
            }
        }
        return p;
    }

    public static void main(String[] args) {
        int[] arr = {1};
        int len = new Q27().removeElement(arr, 1);
        for (int i = 0; i < len; ++i) {
            System.out.println(arr[i]);
        }
    }
}
