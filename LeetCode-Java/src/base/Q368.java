package base;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * Project: LeetCode-Java
 * File: Q368
 *
 * @author evan
 * @date 2021/4/23
 */
public class Q368 {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int len = nums.length;
        LinkedList<Integer> result = new LinkedList<>();
        Arrays.sort(nums);
        int[] dp = new int[len], pos = new int[len];
        int maxVal = Integer.MIN_VALUE, maxPos = 0;
        for (int i = 0; i < len; ++i) {
            pos[i] = i;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pos[i] = j;
                    if (dp[i] > maxVal) {
                        maxVal = dp[i];
                        maxPos = i;
                    }
                }
            }
        }

        while (true) {
            result.addFirst(nums[maxPos]);
            if (maxPos == pos[maxPos]) {
                break;
            }
            maxPos = pos[maxPos];
        }

        return result;
    }

    public static void main(String[] args) {
        Q368 q = new Q368();
        System.out.println(q.largestDivisibleSubset(new int[]{3, 4, 8, 16}));
    }
}
