package interview.beike;

/**
 * Project: LeetCode-Java
 * File: Q04
 *
 * @author evan
 * @date 2021/8/13
 */

class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;
    }

    public TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Q04 {
    public static int isSame(TreeNode a, TreeNode b, int level) {
        if (a == null && b == null) {
            return level + 1;
        }
        if ((a == null || b == null) ) {
            return 0;
        }
        return Math.max(isSame(a.left, b.left, level + 1), isSame(a.right, b.right, level + 1));
    }

    public static int maxSubTree (TreeNode root) {
        // write code here
        return isSame(root.left, root.right, -1);
    }

    public static void main(String[] args) {
        // System.out.println(maxSubTree(new TreeNode(0, new TreeNode(0, new TreeNode(0), null), new TreeNode(0, new TreeNode(0), null))));
        // System.out.println(maxSubTree(new TreeNode(0, new TreeNode(0), new TreeNode(0))));
        System.out.println(maxSubTree(new TreeNode(0, new TreeNode(0), new TreeNode(0, new TreeNode(0), null))));
    }
}
