package base;

/**
 * Project: LeetCode-Java
 * File: Q26
 *
 * @author evan
 * @date 2021/4/18
 */
public class Q26 {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        if (len == 0 || len == 1) {
            return len;
        }
        int p = 1;
        for (int i = 1; i < len; ++i) {
            if (nums[i] != nums[p - 1]) {
                nums[p++] = nums[i];
            }
        }
        return p;
    }

    public static void main(String[] args) {
        int[] arr = {0,0,1,1,1,2,2,3,3,4};
        // int[] arr = {1, 1, 2};
        Q26 q = new Q26();
        int len = q.removeDuplicates(arr);
        for (int i = 0; i < len; ++i) {
            System.out.println(arr[i]);
        }
    }
}
