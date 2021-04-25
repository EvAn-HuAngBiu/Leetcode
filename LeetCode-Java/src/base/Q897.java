package base;

/**
 * Project: LeetCode-Java
 * File: Q897
 *
 * @author evan
 * @date 2021/4/25
 */
public class Q897 {
    private TreeNode head = new TreeNode(-1);
    private TreeNode last = head;

    private void inOrder(TreeNode p) {
        if (p != null) {
            inOrder(p.left);
            last.right = new TreeNode(p.val);
            last = last.right;
            inOrder(p.right);
        }
    }

    public TreeNode increasingBST(TreeNode root) {
        inOrder(root);
        return head.right;
    }

}
