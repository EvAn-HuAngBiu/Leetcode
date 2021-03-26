package base;

/**
 * Project: LeetCode-Java
 * File: Q83
 *
 * @author evan
 * @date 2021/3/26
 */
public class Q83 {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode root = new ListNode(Integer.MIN_VALUE), p = head, q = root, t;
        while (p != null) {
            t = p.next;
            if (p.val > q.val) {
                p.next = null;
                q.next = p;
                q = q.next;
            }
            p = t;
        }
        return root.next;
    }

    public static void main(String[] args) {
        Q83 q = new Q83();
        ListNode head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
        q.deleteDuplicates(head);
    }
}
