package base.fightoffer;

/**
 * <p>
 * Project: LeetCode-Java
 * File: ListNod
 *
 * @author evan
 * @date 2021/9/11
 */
public class ListNode {
    public int val;
    public ListNode next;

    public ListNode() {
        this(-1, null);
    }

    public ListNode(int x) {
        this(x, null);
    }

    public ListNode(int x, ListNode next) {
        this.val = x;
        this.next = next;
    }

    public static ListNode build(int[] array, int idx) {
        if (idx == array.length) {
            return null;
        }
        return new ListNode(array[idx], build(array, idx + 1));
    }

    public static void print(ListNode root) {
        ListNode p = root;
        while (p != null) {
            System.out.println(p.val);
            p = p.next;
        }
    }
}
