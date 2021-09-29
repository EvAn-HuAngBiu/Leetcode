package base;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q142
 *
 * @author evan
 * @date 2021/9/29
 */
public class Q142 {
    public ListNode detectCycle(ListNode head) {
        ListNode p = head, q = head;
        do {
            if (p == null || q == null || q.next == null) {
                return null;
            }
            p = p.next;
            q = q.next.next;
        } while (p != q);

        q = head;
        while (p != q) {
            p = p.next;
            q = q.next;
        }
        return q;
    }
}
