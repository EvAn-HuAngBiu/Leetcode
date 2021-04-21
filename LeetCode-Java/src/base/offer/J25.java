package base.offer;

/**
 * Project: LeetCode-Java
 * File: J25
 *
 * @author evan
 * @date 2021/4/21
 */
public class J25 {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(-1), p = l1, q = l2, t = head;
        while (p != null & q != null) {
            if (p.val < q.val) {
                t.next = p;
                p = p.next;
            } else {
                t.next = q;
                q = q.next;
            }
            t = t.next;
        }
        if (p != null) {
            t.next = p;
        } else {
            t.next = q;
        }
        return head.next;
    }

    public static void main(String[] args) {
        ListNode l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
        ListNode l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
        ListNode merge = new J25().mergeTwoLists(l1, l2);
        merge.print();
    }
}
