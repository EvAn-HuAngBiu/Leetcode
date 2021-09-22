package base.offer2;

import java.util.*;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q11
 *
 * @author evan
 * @date 2021/9/16
 */
public class Q11 {
    public static int findMaxLength(int[] nums) {
        int sum = 0, len = nums.length;
        Map<Integer, List<Integer>> map = new HashMap<>();
        List<Integer> list = new ArrayList<>();
        list.add(0);
        map.put(0, list);
        for (int i = 1; i <= len; ++i) {
            sum += (nums[i - 1] == 0 ? -1 : 1);
            list = map.getOrDefault(sum, new ArrayList<>());
            list.add(i);
            map.put(sum, list);
        }

        int maxValue = Integer.MIN_VALUE;
        Set<Integer> keys = map.keySet();
        for (int key : keys) {
            if (map.get(key).size() < 2) {
                continue;
            }
            list = map.get(key);
            maxValue = Math.max(maxValue, list.get(list.size() - 1) - list.get(0));
        }
        return maxValue == Integer.MIN_VALUE ? 0 : maxValue;
    }

    public static void main(String[] args) {
        int[] array = {0, 1, 0};
        System.out.println(findMaxLength(array));
    }
}
