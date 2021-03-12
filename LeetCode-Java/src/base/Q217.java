package base;

import java.util.HashSet;
import java.util.Set;

/**
 * Project: Leetcode
 * File: Q217
 *
 * @author evan
 * @date 2021/3/12
 */
public class Q217 {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int i : nums) {
            if (set.contains(i)) {
                return true;
            }
            set.add(i);
        }
        return false;
    }

    public static void main(String[] args) {

    }
}
