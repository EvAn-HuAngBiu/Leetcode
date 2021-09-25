package base.offer2;

import base.fightoffer.ListNode;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q23
 *
 * @author evan
 * @date 2021/9/25
 */
public class Q23 {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode p = headA;
        int la = 0, lb = 0;
        while (p != null) {
            p = p.next;
            ++la;
        }

        p = headB;
        while (p != null) {
            p = p.next;
            ++lb;
        }

        int diff;
        if (la > lb) {
            p = headA;
            diff = la - lb;
        } else {
            p = headB;
            diff = lb - la;
        }

        for (int i = 0; i < diff; ++i) {
            p = p.next;
        }
        ListNode q = (la > lb ? headB : headA);
        while (p != null && p != q) {
            p = p.next;
            q = q.next;
        }
        return p;
    }
}
