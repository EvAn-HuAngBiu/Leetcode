package base.offer2;

import base.fightoffer.ListNode;

/**
 * <p>
 * Project: LeetCode-Java
 * File: q25
 *
 * @author evan
 * @date 2021/10/3
 */
public class Q25 {
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int cnt0 = 0, cnt1 = 0;
        ListNode p = l1;
        while (p != null) {
            ++cnt0;
            p = p.next;
        }
        p = l2;
        while (p != null) {
            ++cnt1;
            p = p.next;
        }

        int diff = Math.abs(cnt0 - cnt1);
        int[] result = new int[Math.max(cnt0, cnt1) + 1];

        p = (cnt0 > cnt1 ? l1 : l2);
        for (int i = 1; i <= diff; ++i) {
            result[i] = p.val;
            p = p.next;
        }

        ListNode q = (cnt0 <= cnt1 ? l1 : l2);
        for (int i = 1; i <= Math.min(cnt0, cnt1); ++i) {
            result[++diff] = p.val + q.val;
            p = p.next;
            q = q.next;
        }

        ListNode root = new ListNode(-1);
        for (int i = result.length - 1; i >= 0; --i) {
            if (result[i] >= 10) {
                result[i - 1] += result[i] / 10;
                result[i] %= 10;
            }
            ListNode cur = new ListNode(result[i]);
            cur.next = root.next;
            root.next = cur;
        }

        p = root.next;
        while (p != null && p.val == 0) {
            p = p.next;
        }
        return p == null ? new ListNode(0) : p;
    }

    public static void main(String[] args) {
        ListNode l1 = ListNode.build(new int[] {0}, 0);
        ListNode l2 = ListNode.build(new int[] {7, 3}, 0);
        ListNode result = addTwoNumbers(l1, l2);
        ListNode.print(result);
    }
}
