package base;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Project: LeetCode-Java
 * File: Q268
 *
 * @author evan
 * @date 2021/3/19
 */
public class Q268 {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        int len = nums.length;
        int cur = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] != cur) {
                return cur;
            }
            ++cur;
        }
        return cur;
    }

    public int missingNumber1(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int num : nums) {
            s.add(num);
        }
        int cur = 0;
        while (true) {
            if (!s.contains(cur)) {
                return cur;
            }
            ++cur;
        }
    }

    public int missingNumber2(int[] nums) {
        int len = nums.length;
        int sum = len * (len + 1) / 2;
        for (int num : nums) {
            sum -= num;
        }
        return sum;
    }

    public static void main(String[] args) {
        Q268 q = new Q268();
        int[] nums = {0};
        System.out.println(q.missingNumber2(nums));
    }
}
