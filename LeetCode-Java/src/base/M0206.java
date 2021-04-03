package base;

/**
 * Project: LeetCode-Java
 * File: M0206
 *
 * @author evan
 * @date 2021/4/3
 */
public class M0206 {
    public boolean isPalindrome(ListNode head) {
        ListNode n = head;
        int cnt = 0;
        while (n != null) {
            n = n.next;
            ++cnt;
        }
        n = head;
        for (int i = 0; i < cnt / 2; ++i) {
            n = n.next;
        }
        if (cnt % 2 == 1) {
            n = n.next;
        }
        ListNode p = new ListNode(-1), q;
        while (n != null) {
            q = n.next;
            n.next = p.next;
            p.next = n;
            n = q;
        }

        n = head;
        q = p.next;
        while (q != null) {
            if (n.val != q.val) {
                return false;
            }
            n = n.next;
            q = q.next;
        }
        return true;
    }

    public static void main(String[] args) {
        M0206 m = new M0206();
        // ListNode head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
        // ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(1)))));
        ListNode head = new ListNode(1, new ListNode(2));
        System.out.println(m.isPalindrome(head));
    }
}
