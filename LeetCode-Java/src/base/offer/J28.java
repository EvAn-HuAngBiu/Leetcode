package base.offer;

/**
 * Project: LeetCode-Java
 * File: J28
 *
 * @author evan
 * @date 2021/4/26
 */
public class J28 {
    private boolean compare(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        } else if (p == null || q == null) {
            return false;
        }
        if (p.val == q.val) {
            return compare(p.left, q.left) && compare(p.right, q.right);
        }
        return false;
    }

    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        return compare(root.left, root.right);
    }
}
