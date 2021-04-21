package base.offer;

/**
 * Project: LeetCode-Java
 * File: J22
 *
 * @author evan
 * @date 2021/4/21
 */
public class J22 {
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode p = head;
        for (int i = 0; i < k; ++i) {
            p = p.next;
        }
        ListNode q = head;
        while (p != null) {
            q = q.next;
            p = p.next;
        }
        return q;
    }

    public static void main(String[] args) {
        J22 j = new J22();
        ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        System.out.println(j.getKthFromEnd(head, 2).val);
    }
}
