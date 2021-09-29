package base;

import java.util.HashMap;
import java.util.Map;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q138
 *
 * @author evan
 * @date 2021/9/29
 */
public class Q138 {
    static class Node {
        int val;
        Node next;
        Node random;

        public Node(int val) {
            this.val = val;
            this.next = null;
            this.random = null;
        }
    }

    public static Node copyRandomList(Node head) {
        Map<Node, Node> map = new HashMap<>();
        Node node = new Node(-1), tail = node, p = head;
        while (p != null) {
            Node next = new Node(p.val);
            map.put(p, next);
            tail.next = next;
            tail = tail.next;

            p = p.next;
        }

        p = head;
        tail = node.next;
        while (p != null) {
            tail.random = map.get(p.random);
            p = p.next;
            tail = tail.next;
        }

        return node.next;
    }

    public static Node copyRandomList2(Node head) {
        Node p = head;
        while (p != null) {
            Node next = new Node(p.val);
            next.next = p.next;
            p.next = next;
            p = p.next.next;
        }

        p = head;
        while (p != null) {
            if (p.random != null) {
                p.next.random = p.random.next;
            }
            p = p.next.next;
        }

        Node dummy = new Node(-1), tail = dummy, next;
        p = head;
        while (p != null) {
            next = p.next;
            p.next = next.next;

            next.next = tail.next;
            tail.next = next;
            tail = tail.next;
            p = p.next;
        }

        return dummy.next;
    }
}
