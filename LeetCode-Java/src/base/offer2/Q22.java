package base.offer2;

import base.fightoffer.ListNode;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q22
 *
 * @author evan
 * @date 2021/9/25
 */
public class Q22 {
    public static ListNode detectCycle(ListNode head) {
        ListNode p = head, q = head;
        do {
            if (q.next == null || q.next.next == null) {
                return null;
            }
            p = p.next;
            q = q.next.next;
        } while (p != q);

        q = p;
        p = head;
        while (p != q) {
            p = p.next;
            q = q.next;
        }

        return p;
    }
}
