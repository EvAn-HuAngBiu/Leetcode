package base;

/**
 * Project: LeetCode-Java
 * File: Q95
 *
 * @author evan
 * @date 2021/3/18
 */
public class Q92 {
    class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode pre = new ListNode(-1, head);
        ListNode p = pre, q = head;
        for (int i = 1; i < left; i++) {
            p = p.next;
            q = q.next;
        }
        ListNode last = q;
        ListNode t;
        p.next = null;
        for (int i = 0; i <= right - left; i++) {
            t = q.next;
            q.next = p.next;
            p.next = q;
            q = t;
        }
        last.next = q;
        return pre.next;
    }

    public static void main(String[] args) {
        Q92 q = new Q92();
        Q92.ListNode head = q.new ListNode(1, q.new ListNode(2, q.new ListNode(3, q.new ListNode(4, q.new ListNode(5)))));
        q.reverseBetween(head, 1, 1);

    }
}
