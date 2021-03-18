package base;

/**
 * Project: LeetCode-Java
 * File: Q235
 *
 * @author evan
 * @date 2021/3/18
 */
public class Q235 {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode cur = root;
        while (true) {
            if (p.val > cur.val && q.val > cur.val) {
                cur = cur.right;
            } else if (p.val < cur.val && q.val < cur.val) {
                cur = cur.left;
            } else {
                return cur;
            }
        }
    }

    public static void main(String[] args) {
        Q235 q = new Q235();
        TreeNode t = new TreeNode(6, new TreeNode(2, new TreeNode(0), new TreeNode(4, new TreeNode(3), new TreeNode(5))), new TreeNode(8, new TreeNode(7), new TreeNode(9)));
        System.out.println(q.lowestCommonAncestor(t, new TreeNode(2), new TreeNode(8)).val);
    }
}
