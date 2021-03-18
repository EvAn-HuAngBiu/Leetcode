package base;

/**
 * Project: LeetCode-Java
 * File: Q239
 *
 * @author evan
 * @date 2021/3/18
 */
public class Q237 {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }

    public static void main(String[] args) {

    }
}
