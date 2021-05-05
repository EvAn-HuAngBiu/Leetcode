package base;

import java.util.HashMap;
import java.util.Map;

/**
 * Project: LeetCode-Java
 * File: Q137
 *
 * @author evan
 * @date 2021/4/30
 */
public class Q137 {
    public int singleNumber(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        for (int key : map.keySet()) {
            if (map.get(key) != 3) {
                return key;
            }
        }
        return -1;
    }

    public static int singleNumber2(int[] nums) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int num : nums) {
                if ((num >>> i & 1) == 1) {
                    ++cnt;
                }
            }
            result |= (cnt % 3) << i;
        }
        return result;
    }

    public static void main(String[] args) {
        int[] nums = {0,1,0,1,0,1,99};
        System.out.println(singleNumber2(nums));
    }
}
