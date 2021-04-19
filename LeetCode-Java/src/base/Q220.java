package base;

import java.util.TreeSet;

/**
 * Project: LeetCode-Java
 * File: Q220
 *
 * @author evan
 * @date 2021/4/17
 */
public class Q220 {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        TreeSet<Long> set = new TreeSet<>();
        int len = nums.length;
        if (len == 0 || len == 1) {
            return false;
        }
        set.add((long) nums[0]);
        for (int i = 1; i < len; ++i) {
            if (set.size() == k + 1) {
                set.remove((long)nums[i - k - 1]);
            }
            Long upper = set.floor((long) nums[i]), lower = set.ceiling((long) nums[i]);
            if ((upper != null && nums[i] - upper <= t) ||
                    (lower != null && lower - nums[i] <= t)) {
                return true;
            }
            set.add((long) nums[i]);
        }
        return false;
    }

    public static void main(String[] args) {
        int[] arr = {1,2,3,1};
        System.out.println(new Q220().containsNearbyAlmostDuplicate(arr, 3, 0));
    }
}
