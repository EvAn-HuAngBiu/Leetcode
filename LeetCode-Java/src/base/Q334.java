package base;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q334
 *
 * @author evan
 * @date 2021/9/6
 */
public class Q334 {
    public static boolean increasingTriplet(int[] nums) {
        int min = Integer.MAX_VALUE, mid = Integer.MAX_VALUE;
        for (int num : nums) {
            if (num <= min) {
                min = num;
            } else if (num <= mid) {
                mid = num;
            } else {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[] n = {5,4,3,2,1};
        System.out.println(increasingTriplet(n));
    }
}
