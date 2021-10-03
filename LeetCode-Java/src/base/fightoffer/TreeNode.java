package base.fightoffer;

/**
 * <p>
 * Project: LeetCode-Java
 * File: TreeNode
 *
 * @author evan
 * @date 2021/9/12
 */
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    public TreeNode(int x) {
        this(x, null, null);
    }

    public TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
