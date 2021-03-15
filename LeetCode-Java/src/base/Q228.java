package base;

import java.util.ArrayList;
import java.util.List;

/**
 * Project: LeetCode-Java
 * File: Q228
 *
 * @author evan
 * @date 2021/3/15
 */
public class Q228 {
    public List<String> summaryRanges(int[] nums) {
        int p = 0, len = nums.length;
        List<String> result = new ArrayList<>();
        if (len == 0) {
            return result;
        } else if (len == 1) {
            return List.of(String.valueOf(nums[0]));
        }
        for (int i = 1; i < len; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                if (p == i - 1) {
                    result.add(String.valueOf(nums[p]));
                } else {
                    result.add(nums[p] + "->" + nums[i - 1]);
                }
                p = i;
            }
        }
        if (p == len - 1) {
            result.add(String.valueOf(nums[p]));
        } else {
            result.add(nums[p] + "->" + nums[len - 1]);
        }
        return result;
    }

    public static void main(String[] args) {
        Q228 q = new Q228();
        int[] nums = {0};
        System.out.println(q.summaryRanges(nums));
    }
}
