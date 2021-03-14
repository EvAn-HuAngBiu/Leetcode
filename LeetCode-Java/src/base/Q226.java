package base;

/**
 * Project: LeetCode-Java
 * File: Q226
 *
 * @author evan
 * @date 2021/3/14
 */

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

public class Q226 {
    private void levelLoop(TreeNode root) {
        if (root != null) {
            TreeNode left = root.left, right = root.right;
            root.left = right;
            root.right = left;
            levelLoop(left);
            levelLoop(right);
        }
    }

    public TreeNode invertTree(TreeNode root) {
        levelLoop(root);
        return root;
    }

    public static void main(String[] args) {

    }
}
