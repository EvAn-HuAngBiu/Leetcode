package base;

import java.util.HashSet;
import java.util.Set;

/**
 * Project: LeetCode-Java
 * File: J03
 *
 * @author evan
 * @date 2021/4/4
 */
public class J03 {
    public int findRepeatNumber(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int i : nums) {
            if (set.contains(i)) {
                return i;
            }
            set.add(i);
        }
        return -1;
    }
}
