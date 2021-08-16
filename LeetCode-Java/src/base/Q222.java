package base;

/**
 * Project: LeetCode-Java
 * File: Q222
 *
 * @author evan
 * @date 2021/8/16
 */
public class Q222 {
    public static int countNodes(TreeNode root) {
        return root == null ? 0 : 1 + countNodes(root.left) + countNodes(root.right);
    }

    public static int countNodes2(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = countLevel(root.left), right = countLevel(root.right);
        if (left == right) {
            /*
            * 左子树层数等于右子树说明要么左右子树都是完全二叉树，要么最右的叶子在右子树上
            * 因为层数是指当前子树最深的层数
            *            1
            *          /  \
            *        2     3
            *      /  \  /
            *     4   5 6
            *
            * 比如上面这个树，统计2和3子树结点可以知道它们的层数都是2，但是此时由于是完全二叉树
            * 所以即使存在空节点也一定在右子树上，所以左子树一定是满二叉树，只要统计右子树即可
            * */
            return countNodes2(root.right) + (1 << left);
        } else {
            /*
             * 反之说明左子树上存在空节点，那么右子树一定是一个满二叉树，统计左子树即可
             *            1
             *          /  \
             *        2     3
             *      /
             *     4
             * */
            return countNodes2(root.left) + (1 << right);
        }
    }

    public static int countLevel(TreeNode root) {
        int level = 0;
        TreeNode p = root;
        while (p != null) {
            p = p.left;
            ++level;
        }
        return level;
    }
}
