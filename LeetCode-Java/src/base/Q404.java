package base;

/**
 * Project: LeetCode-Java
 * File: Q404
 *
 * @author evan
 * @date 2021/6/23
 */
public class Q404 {
    public static int sum = 0;

    public static int sumOfLeftLeaves(TreeNode root) {
        if (root.left != null) {
            loop(root.left, true);
        }
        if (root.right != null) {
            loop(root.right, false);
        }
        return sum;
    }

    public static void loop(TreeNode p, boolean isLeft) {
        if (p.left == null && p.right == null) {
            sum += (isLeft ? p.val : 0);
        }
        if (p.left != null) {
            loop(p.left, true);
        }
        if (p.right != null) {
            loop(p.right, false);
        }
    }
}
