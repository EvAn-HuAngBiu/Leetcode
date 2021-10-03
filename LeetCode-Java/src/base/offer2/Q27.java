package base.offer2;

import base.fightoffer.ListNode;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q27
 *
 * @author evan
 * @date 2021/10/3
 */
public class Q27 {
    public static boolean isPalindrome(ListNode head) {
        int cnt = 0;
        ListNode p = head;
        while (p != null) {
            ++cnt;
            p = p.next;
        }
        if (cnt <= 1) {
            return true;
        }

        ListNode half = new ListNode(-1), ne;
        p = head;
        for (int i = 0; i < cnt / 2; ++i) {
            p = p.next;
        }
        if (cnt % 2 == 1) {
            p = p.next;
        }
        while (p != null) {
            ne = p.next;
            p.next = half.next;
            half.next = p;
            p = ne;
        }

        p = head;
        ne = half.next;
        while (ne != null) {
            if (p.val != ne.val) {
                return false;
            }
            p = p.next;
            ne = ne.next;
        }
        return true;
    }

    public static void main(String[] args) {
        ListNode node = ListNode.build(new int[] {1, 2, 3, 3, 2, 1}, 0);
        System.out.println(isPalindrome(node));
    }
}
