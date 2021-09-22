package base;

import java.util.*;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q23
 *
 * @author evan
 * @date 2021/9/22
 */
public class Q23 {
    public static ListNode mergeKLists(ListNode[] lists) {
        int len = lists.length;
        if (len == 0) {
            return null;
        } else if (len == 1) {
            return lists[0];
        }

        PriorityQueue<ListNode> pq = new PriorityQueue<>(Comparator.comparingInt(p -> p.val));
        for (ListNode list : lists) {
            pq.add(list == null ? new ListNode(Integer.MAX_VALUE) : list);
        }

        ListNode result = new ListNode(), tail = result;

        while (!pq.isEmpty()) {
            ListNode node = pq.poll();
            if (node.val == Integer.MAX_VALUE) {
                break;
            }

            tail.next = node;
            tail = tail.next;

            pq.add(Objects.requireNonNullElseGet(node.next, () -> new ListNode(Integer.MAX_VALUE)));
        }
        tail.next = null;
        return result.next;
    }

    public static void main(String[] args) {
        ListNode n1 = new ListNode(1, new ListNode(4, new ListNode(5)));
        ListNode n2 = new ListNode(1, new ListNode(3, new ListNode(4)));
        ListNode n3 = new ListNode(2, new ListNode(6));

        // ListNode result = mergeKLists(new ListNode[] {n1, n2, n3});
        ListNode p = mergeKLists(new ListNode[] {null, null});

        while (p != null) {
            System.out.println(p.val);
            p = p.next;
        }
    }
}
