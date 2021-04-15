package base.offer;

import java.util.Optional;

/**
 * Project: LeetCode-Java
 * File: J18
 *
 * @author evan
 * @date 2021/4/15
 */
public class J18 {
    public ListNode deleteNode(ListNode head, int val) {
        // 定义一个伪头结点
        ListNode root = new ListNode(-1, head), p = root;
        while (p.next != null) {
            if (p.next.val == val) {
                p.next = p.next.next;
                break;
            }
            p = p.next;
        }
        return root.next;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(4, new ListNode(5, new ListNode(1, new ListNode(9))));
        // 注意删除唯一节点会变null
        // ListNode head = new ListNode(4);
        J18 j = new J18();
        head = Optional.ofNullable(j.deleteNode(head, 4)).orElse(new ListNode(Integer.MIN_VALUE));
        head.print();
    }
}
