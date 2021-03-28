package base;

import java.util.Deque;
import java.util.LinkedList;

/**
 * Project: LeetCode-Java
 * File: Q345
 *
 * @author evan
 * @date 2021/3/28
 */
public class Q345 {
    public String reverseVowels(String s) {
        Deque<Integer> index = new LinkedList<>();
        char[] arr = s.toCharArray();
        int len = arr.length;
        for (int i = 0; i < len; ++i) {
            if ("aeiouAEIOU".contains(String.valueOf(arr[i]))) {
                index.push(i);
            }
        }
        int times = index.size() / 2;
        for (int i = 0; i < times; ++i) {
            Integer p = index.pollFirst(), q = index.pollLast();
            char temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
        }
        return new String(arr);
    }

    public static void main(String[] args) {
        Q345 q = new Q345();
        System.out.println(q.reverseVowels("leetcod"));
    }
}
