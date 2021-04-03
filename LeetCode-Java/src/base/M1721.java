package base;

import java.util.Deque;
import java.util.LinkedList;

/**
 * Project: LeetCode-Java
 * File: M1721
 *
 * @author evan
 * @date 2021/4/2
 */
public class M1721 {
    public int trap(int[] height) {
        Deque<Integer> stack = new LinkedList<>();
        int result = 0;
        for (int i = 0; i < height.length; i++) {
            while (!stack.isEmpty() && height[i] > height[stack.peek()]) {
                int top = stack.poll();
                if (stack.isEmpty()) {
                    break;
                }
                int left = stack.peek();
                result += (i - left - 1) * (Math.min(height[i], height[left]) - height[top]);
            }
            stack.push(i);
        }
        return result;
    }

    public static void main(String[] args) {
        // int[] array = {0,1,0,2,1,0,1,3,2,1,2,1};
        // int[] array = {2,0,0,2};
        int[] array = {4,2,3};
        M1721 m = new M1721();
        System.out.println(m.trap(array));
    }
}
