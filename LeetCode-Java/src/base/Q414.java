package base;

import java.util.*;

/**
 * Project: LeetCode-Java
 * File: Q414
 *
 * @author evan
 * @date 2021/8/7
 */
public class Q414 {
    public static int thirdMax(int[] nums) {
        TreeSet<Integer> set = new TreeSet<>(Comparator.reverseOrder());
        for (int num : nums) {
            set.add(num);
        }
        if (set.size() < 3) {
            return set.first();
        }
        Iterator<Integer> it = set.iterator();
        int result = -1;
        for (int i = 0; i < 3; ++i) {
            result = it.next();
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(thirdMax(new int[] {1, 2, 2, 5, 3, 5}));
    }
}
