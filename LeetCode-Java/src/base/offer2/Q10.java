package base.offer2;

import java.util.*;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q10
 *
 * @author evan
 * @date 2021/9/16
 */
public class Q10 {
    public static int subarraySum(int[] nums, int k) {
        int len = nums.length;
        if (len == 0) {
            return 0;
        }
        Map<Integer, List<Integer>> map = new HashMap<>();
        List<Integer> list = new ArrayList<>();
        list.add(0);
        map.put(0, list);
        int sum = 0;
        for (int i = 1; i <= len; ++i) {
            sum += nums[i - 1];
            list = map.getOrDefault(sum, new ArrayList<>());
            list.add(i);
            map.put(sum, list);
        }

        int result = 0;
        Set<Integer> keys = map.keySet();
        for (Integer key : keys) {
            if (map.containsKey(k + key)) {
                for (int val : map.get(k + key)) {
                    result += map.get(key).stream().filter(v -> v < val).count();
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] nums = {1, 1, 1};
        System.out.println(subarraySum(nums, 2));
    }
}
