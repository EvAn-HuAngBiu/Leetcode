package base.offer;

/**
 * Project: LeetCode-Java
 * File: J24
 *
 * @author evan
 * @date 2021/4/21
 */
public class J24 {
    public ListNode reverseList(ListNode head) {
        ListNode p = new ListNode(-1), q = head, t;
        while (q != null) {
            t = q.next;
            q.next = p.next;
            p.next = q;
            q = t;
        }
        return p.next;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        ListNode reverse = new J24().reverseList(head);
        reverse.print();
    }
}
