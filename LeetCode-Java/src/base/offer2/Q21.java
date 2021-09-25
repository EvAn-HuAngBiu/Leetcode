package base.offer2;

import base.fightoffer.ListNode;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q21
 *
 * @author evan
 * @date 2021/9/25
 */
public class Q21 {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode root = new ListNode();
        root.next = head;
        ListNode p = head, q = head, pred = root;
        for (int i = 0; i < n; ++i) {
            q = q.next;
        }

        while (q != null) {
            p = p.next;
            q = q.next;
            pred = pred.next;
        }

        pred.next = p.next;
        return root.next;
    }
}
