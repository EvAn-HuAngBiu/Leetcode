package base;

/**
 * Project: LeetCode-Java
 * File: Q938
 *
 * @author evan
 * @date 2021/4/27
 */
public class Q938 {
    private int sum = 0;

    private void inOrder(TreeNode p, int low, int high) {
        if (p != null) {
            if (p.val >= low) {
                inOrder(p.left, low, high);
            }
            if (p.val >= low && p.val <= high) {
                sum += p.val;
            }
            if (p.val <= high) {
                inOrder(p.right, low, high);
            }
        }
    }

    public int rangeSumBST(TreeNode root, int low, int high) {
        inOrder(root, low, high);
        return sum;
    }
}
