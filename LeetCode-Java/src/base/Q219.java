package base;

import java.util.HashSet;
import java.util.Set;

/**
 * Project: LeetCode-Java
 * File: Q219
 *
 * @author evan
 * @date 2021/3/12
 */
public class Q219 {
    /**
     * 复杂度O(n2) 硬比较窗口k内的元素
     * */
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        int len = nums.length;
        for (int i = k; i > 0; --i) {
            for (int j = 0; j + i < len; ++j) {
                if (nums[j] == nums[j + i]) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * 学习：滑动窗口哈希表即可，窗口k的意义是半径为k的范围存在的数，利用哈希表判断有没重复，
     *      每当超过长度时删除哈希表的第一个元素即可
     * */
    public boolean containsNearbyDuplicate2(int[] nums, int k) {
        Set<Integer> set = new HashSet<>();
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            if (set.contains(nums[i])) {
                return true;
            }
            set.add(nums[i]);
            if (set.size() > k) {
                set.remove(nums[i - k]);
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[] nums = {1,2,1};
        Q219 q = new Q219();
        System.out.println(q.containsNearbyDuplicate2(nums, 0));
    }
}
