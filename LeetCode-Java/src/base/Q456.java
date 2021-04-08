package base;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * Project: LeetCode-Java
 * File: Q456
 *
 * @author evan
 * @date 2021/3/24
 */
public class Q456 {
    private boolean[] used;

    private boolean dfs(int[] nums, List<Integer> pre, int index) {
        int cnt = pre.size(), len = nums.length;
        if (cnt == 3) {
            return true;
        }
        for (int i = index; i < len; i++) {
            if (!used[i]) {
                if ((cnt == 1 && nums[i] > pre.get(0)) ||
                        (cnt == 2 && nums[i] > pre.get(0) && nums[i] < pre.get(1))) {
                    used[i] = true;
                    pre.add(nums[i]);
                    if (dfs(nums, pre, i + 1)) {
                        return true;
                    }
                    pre.remove(cnt);
                    used[i] = false;
                }
            }
        }
        return false;
    }

    public boolean find132pattern(int[] nums) {
        int len = nums.length;
        used = new boolean[len];
        for (int i = 0; i < len; ++i) {
            used[i] = true;
            List<Integer> list = new ArrayList<>();
            list.add(nums[i]);
            if (dfs(nums, list, i + 1)) {
                return true;
            }
            list.remove(0);
            used[i] = false;
        }
        return false;
    }

    private int rangeMax(int[] nums, int begin, int end, int bound) {
        int max = nums[begin], index = begin;
        for (int i = begin + 1; i <= end; ++i) {
            if (nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }
        return index;
    }

    private int rangeMin(int[] nums, int begin, int end, int bound) {
        int min = nums[begin], index = begin;
        for (int i = begin + 1; i <= end; ++i) {
            if (nums[i] < min) {
                min = nums[i];
                index = i;
            }
        }
        return index;
    }

    public boolean find132pattern2(int[] nums) {
        int len = nums.length;
        if (len < 3) {
            return false;
        }
        LinkedList<Integer> stack = new LinkedList<>();
        int midMaxIndex;
        for (midMaxIndex = 0; midMaxIndex < len; midMaxIndex++) {
            if (stack.isEmpty() || nums[midMaxIndex] < stack.peekLast()) {
                stack.push(nums[midMaxIndex]);
            } else {
                break;
            }
        }
        if (midMaxIndex == 0 || midMaxIndex >= len - 1) {
            return false;
        }
        // int midMaxIndex = rangeMax(nums, 1, len - 2);
        // int leftMinIndex = rangeMin(nums, 0, midMaxIndex - 1);
        // int rightMaxIndex = rangeMax(nums, midMaxIndex + 1, len - 1);
        // return nums[midMaxIndex] > nums[leftMinIndex] && nums[midMaxIndex] > nums[rightMaxIndex] && nums[leftMinIndex] < nums[rightMaxIndex];
        return true;
    }


    public static void main(String[] args) {
        Q456 q = new Q456();
        int[] nums = {1,3,2,4,5,6,7,8,9,10};
        System.out.println(q.find132pattern2(nums));
    }
}
