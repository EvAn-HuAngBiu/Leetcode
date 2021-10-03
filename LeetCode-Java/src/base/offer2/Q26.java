package base.offer2;

import base.fightoffer.ListNode;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q26
 *
 * @author evan
 * @date 2021/10/3
 */
public class Q26 {
    public static void reorderList(ListNode head) {
        int cnt = 0;
        ListNode p = head;
        while (p != null) {
            ++cnt;
            p = p.next;
        }
        if (cnt <= 1) {
            return;
        }

        p = head;
        for (int i = 0; i < cnt / 2 - 1; ++i) {
            p = p.next;
        }
        if (cnt % 2 != 0) {
            p = p.next;
        }
        ListNode reverse = new ListNode(-1), ne = p.next, q;
        p.next = null;
        p = ne;
        while (p != null) {
            ne = p.next;
            p.next = reverse.next;
            reverse.next = p;
            p = ne;
        }

        p = reverse.next;
        q = head;
        while (p != null) {
            ne = p.next;
            p.next = q.next;
            q.next = p;
            q = q.next.next;
            p = ne;
        }
    }

    public static void main(String[] args) {
        ListNode head = ListNode.build(new int[] {1, 2, 3, 4, 5, 6}, 0);
        reorderList(head);
        ListNode.print(head);
    }
}
