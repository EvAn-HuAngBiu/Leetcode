package base;

/**
 * Project: LeetCode-Java
 * File: Q147
 *
 * @author evan
 * @date 2021/8/13
 */
public class Q147 {
    public static ListNode insertionSortList(ListNode head) {
        ListNode newHead = new ListNode(Integer.MIN_VALUE);
        ListNode pre, cur = head, find, next;
        while (cur != null) {
            pre = newHead;
            find = pre.next;
            next = cur.next;
            while (find != null) {
                if (find.val > cur.val) {
                    cur.next = pre.next;
                    pre.next = cur;
                    break;
                }
                pre = pre.next;
                find = find.next;
            }
            if (find == null) {
                pre.next = cur;
                cur.next = null;
            }
            cur = next;
        }
        return newHead.next;
    }

    public static void main(String[] args) {
        ListNode list = new ListNode(-1, new ListNode(5, new ListNode(3, new ListNode(4, new ListNode(0)))));
        ListNode sorted = insertionSortList(list), p = sorted;
        while (p != null) {
            System.out.println(p.val);
            p = p.next;
        }
    }
}
