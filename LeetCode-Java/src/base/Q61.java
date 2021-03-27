package base;

/**
 * Project: LeetCode-Java
 * File: Q61
 *
 * @author evan
 * @date 2021/3/27
 */
public class Q61 {
    public ListNode rotateRight(ListNode head, int k) {
        ListNode p = head;
        int cnt = 0;
        while (p != null) {
            p = p.next;
            ++cnt;
        }
        if (cnt == 0 || k % cnt == 0) {
            return head;
        }
        // 快慢指针
        p = head;
        ListNode q = p;
        for (int i = 0; i < k % cnt; i++) {
            q = q.next;
        }
        while (q.next != null) {
            p = p.next;
            q = q.next;
        }
        ListNode r = p.next;
        p.next = null;
        q.next = head;
        return r;
    }

    public static void main(String[] args) {
        // ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        ListNode head = new ListNode(0, new ListNode(1, new ListNode(2)));
        Q61 q = new Q61();
        ListNode listNode = q.rotateRight(head, 6);
        System.out.println(listNode);
    }
}
