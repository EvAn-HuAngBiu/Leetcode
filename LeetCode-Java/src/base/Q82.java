package base;

/**
 * Project: LeetCode-Java
 * File: Q82
 *
 * @author evan
 * @date 2021/3/25
 */
public class Q82 {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode root = new ListNode(-1, head);
        if (head == null || head.next == null) {
            return head;
        }
        ListNode p = root, q = head, r = head.next;
        while (r != null) {
            if (q.val == r.val) {
                while (r != null && q.val == r.val) {
                    q.next = r.next;
                    r = r.next;
                }
                p.next = r;
                q = r;
                if (r != null) {
                    r = r.next;
                }
            } else {
                p = p.next;
                q = q.next;
                r = r.next;
            }
        }
        return root.next;
    }

    public static void main(String[] args) {
        // ListNode l = new ListNode(1, new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(3)))))));
        ListNode l = new ListNode(1, new ListNode(1));
        Q82 q = new Q82();
        q.deleteDuplicates(l);
        System.out.println(q);
    }
}
