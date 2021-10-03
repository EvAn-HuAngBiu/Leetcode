package base.offer2;

import base.fightoffer.ListNode;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q024
 *
 * @author evan
 * @date 2021/10/3
 */
public class Q024 {
    public ListNode reverseList(ListNode head) {
        ListNode root = new ListNode(-1), p = head, next;
        while (p != null) {
            next = p.next;
            p.next = root.next;
            root.next = p;
            p = next;
        }
        return root.next;
    }
}
