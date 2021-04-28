package base;

import java.util.Arrays;

/**
 * Project: LeetCode-Java
 * File: Q1838
 *
 * @author evan
 * @date 2021/4/28
 */
public class Q1838 {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int maxTime = 0, len = nums.length;
        for (int i = len - 1; i >= 0; --i) {
            int time = 1, count = 0;
            for (int j = i - 1; j >= 0 && count < k; --j) {
                if (count + nums[i] - nums[j] <= k) {
                    count += nums[i] - nums[j];
                    ++time;
                }
            }
            maxTime = Math.max(maxTime, time);
        }
        return maxTime;
    }

    public int maxFrequency2(int[] nums, int k) {
        Arrays.sort(nums);
        int start = 0, result = 1, curTime = 0, len = nums.length;
        for (int i = 1; i < len; ++i) {
            curTime += (nums[i] - nums[i - 1]) * (i - start);
            while (curTime > k) {
                curTime -= nums[i] - nums[start++];
            }
            result = Math.max(result, i - start + 1);
        }
        return result;
    }

    public static void main(String[] args) {
        Q1838 q = new Q1838();
        int[] nums = {3, 9, 6};
        System.out.println(q.maxFrequency2(nums, 2));
    }
}
