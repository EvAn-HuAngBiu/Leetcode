package base;

import java.util.Deque;
import java.util.LinkedList;

/**
 * Project: LeetCode-Java
 * File: J06
 *
 * @author evan
 * @date 2021/4/7
 */
public class J06 {
    public int[] reversePrint(ListNode head) {
        ListNode p = head;
        int cnt = 0;
        while (p != null) {
            ++cnt;
            p = p.next;
        }
        int[] result = new int[cnt];
        p = head;
        int q = cnt - 1;
        while (p != null) {
            result[q--] = p.val;
            p = p.next;
        }
        return result;
    }

    public int[] reversePrint2(ListNode head) {
        Deque<Integer> deque = new LinkedList<>();
        ListNode p = head;
        while (p != null) {
            deque.push(p.val);
            p = p.next;
        }
        return deque.stream().mapToInt(q -> q).toArray();
    }
}
