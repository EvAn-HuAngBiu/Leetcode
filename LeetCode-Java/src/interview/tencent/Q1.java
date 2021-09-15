package interview.tencent;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q1
 *
 * @author evan
 * @date 2021/9/5
 */

class ListNode {
    int val;
    ListNode next = null;

    public ListNode(int val) {
        this(val, null);
    }

    public ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class Q1 {
    public static ListNode solve(ListNode[] a) {
        int len = a.length;
        ListNode head = new ListNode(-1), last = head;
        boolean flag;
        do {
            flag = true;
            for (int i = 0; i < len; ++i) {
                if (a[i] != null) {
                    flag = false;
                    last.next = new ListNode(a[i].val);
                    last = last.next;
                    a[i] = a[i].next;
                }
            }
        } while (!flag);

        return head.next;
    }

    public static void main(String[] args) {
        ListNode a = new ListNode(1, new ListNode(2, new ListNode(3))),
                b = new ListNode(4, new ListNode(5)),
                c = new ListNode(7, new ListNode(8, new ListNode(9, new ListNode(10, new ListNode(11, new ListNode(12))))));
        ListNode[] n = {a, b, c};
        ListNode l = solve(n);
        while (l != null) {
            System.out.println(l.val);
            l = l.next;
        }
    }
}
