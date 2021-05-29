package base;

import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

/**
 * Project: LeetCode-Java
 * File: Q128
 *
 * @author evan
 * @date 2021/5/29
 */
public class Q128 {
    public static int longestConsecutive(int[] nums) {
        Map<Integer, Integer> map = new TreeMap<>();
        for (int num : nums) {
            map.put(num, 1);
        }
        int maxLen = 0;
        for (Integer key : map.keySet()) {
            int cur = map.getOrDefault(key - 1, 0) + 1;
            map.put(key, cur);
            maxLen = Math.max(maxLen, cur);
        }
        return maxLen;
    }

    public static void main(String[] args) {
        int[] nums = {0,3,7,2,5,8,4,6,0,1};
        System.out.println(longestConsecutive(nums));
    }
}
