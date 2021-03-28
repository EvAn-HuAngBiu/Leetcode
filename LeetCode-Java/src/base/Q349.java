package base;

import java.util.*;

/**
 * Project: LeetCode-Java
 * File: Q349
 *
 * @author evan
 * @date 2021/3/28
 */
public class Q349 {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> s1 = new HashSet<>(), s2 = new HashSet<>();
        for (int i : nums1) {
            s1.add(i);
        }
        for (int i : nums2) {
            s2.add(i);
        }
        List<Integer> result = new ArrayList<>();
        for (Integer cur : s1) {
            if (s2.contains(cur)) {
                result.add(cur);
            }
        }
        int[] r = new int[result.size()];
        for (int i = 0; i < result.size(); ++i) {
            r[i] = result.get(i);
        }
        return r;
    }

    public static void main(String[] args) {

    }
}
