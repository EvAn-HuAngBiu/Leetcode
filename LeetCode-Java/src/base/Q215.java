package base;

import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q215
 *
 * @author evan
 * @date 2021/9/29
 */
public class Q215 {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(nums.length, Comparator.reverseOrder());
        for (int num : nums) {
            pq.add(num);
        }
        for (int i = 1; i < k; ++i) {
            pq.poll();
        }
        return pq.poll();
    }
}
