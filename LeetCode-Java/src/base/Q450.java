package base;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q450
 *
 * @author evan
 * @date 2021/8/22
 */

public class Q450 {
    private static TreeNode[] find(TreeNode parent, TreeNode current, int key) {
        while (current != null && current.val != key) {
            parent = current;
            if (current.val > key) {
                current = current.left;
            } else {
                current = current.right;
            }
        }
        return new TreeNode[]{parent, current};
    }

    private static void doDelete(TreeNode parent, TreeNode current) {
        if (current.left == null && current.right == null) {
            // 删除结点是叶子结点的情况
            if (parent.left == current) {
                parent.left = null;
            } else {
                parent.right = null;
            }
        } else if (current.left == null || current.right == null) {
            // 删除结点只有一个叶子结点的情况
            if (current == parent.left) {
                parent.left = (current.left == null ? current.right : current.left);
            } else {
                parent.right = (current.left == null ? current.right : current.left);
            }
        } else {
            TreeNode nextParent = current, next = current.right;
            while (next.left != null) {
                nextParent = next;
                next = next.left;
            }
            current.val = next.val;
            doDelete(nextParent, next);
        }
    }

    public static TreeNode deleteNode(TreeNode root, int key) {
        TreeNode[] deletedNode = find(null, root, key);
        TreeNode parent = deletedNode[0], current = deletedNode[1];
        if (current == null) {
            // 二茬搜索树中不存在目标结点
            return root;
        }
        // 单独处理根节点删除问题
        if (parent == null) {
            if (current.left == null && current.right == null) {
                // 唯一结点删除，置空即可
                return null;
            } else if (current.left == null || current.right == null) {
                // 只存在左、右子树中的一个
                return (current.left == null ? current.right : current.left);
            }
            // 否则按照正常流程删除
        }
        doDelete(parent, current);
        return root;
    }

    public static void main(String[] args) {
        // TreeNode root = new TreeNode(5,
        //         new TreeNode(3),
        //         new TreeNode(7, new TreeNode(6), new TreeNode(10, new TreeNode(8), null)));
        TreeNode root = new TreeNode(0, new TreeNode(1), null);
        root = deleteNode(root, 0);
    }
}
