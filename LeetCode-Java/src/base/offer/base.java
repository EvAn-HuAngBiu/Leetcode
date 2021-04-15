package base.offer;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

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

    public void print() {
        ListNode p = this;
        while (p.next != null) {
            System.out.print(p.val + "->>");
            p = p.next;
        }
        System.out.println(p.val);
    }
}

/**
 * 定义公共数据结构
 */
public class base {
    
}
