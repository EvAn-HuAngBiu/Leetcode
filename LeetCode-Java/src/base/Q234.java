package base;

/**
 * Project: LeetCode-Java
 * File: Q234
 *
 * @author evan
 * @date 2021/3/17
 */

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
public class Q234 {
    public boolean isPalindrome(ListNode head) {
        ListNode p = head, q;
        // 计数
        int cnt = 0;
        while (p != null) {
            p = p.next;
            cnt++;
        }
        if (cnt == 1) {
            return true;
        }
        // if (cnt % 2 != 0) {
        //     return false;
        // }

        // 后半部分就地逆置
        p = head;
        for (int i = 0; i < cnt / 2 - 1; i++) {
            p = p.next;
        }
        q = p.next;
        if (cnt % 2 == 1) {
            q = q.next;
        }
        p.next = null;
        ListNode t;
        while (q != null) {
            t = q.next;
            q.next = p.next;
            p.next = q;
            q = t;
        }

        // 快慢指针
        p = head;
        q = head;
        for (int i = 0; i < cnt / 2; i++) {
            q = q.next;
        }
        while (q != null) {
            if (p.val != q.val) {
                return false;
            }
            p = p.next;
            q = q.next;
        }
        return true;
    }

    public static void main(String[] args) {
        ListNode n1 = new ListNode(1);
        Q234 q = new Q234();
        System.out.println(q.isPalindrome(n1));
    }
}
