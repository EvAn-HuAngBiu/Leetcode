package base.offer;

/**
 * Project: LeetCode-Java
 * File: J26
 *
 * @author evan
 * @date 2021/4/26
 */
public class J26 {
    private boolean compare(TreeNode p, TreeNode q) {
        if (q == null) {
            return true;
        } else if (p == null) {
            return false;
        }
        if (p.val == q.val) {
            return compare(p.left, q.left) && compare(p.right, q.right);
        } else {
            return false;
        }
    }

    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if (A == null || B == null) {
            return false;
        }
        boolean cmp = compare(A, B);
        if (cmp) {
            return true;
        }
        return isSubStructure(A.left, B) || isSubStructure(A.right, B);
    }

    public static void main(String[] args) {
        J26 j = new J26();
        TreeNode a = new TreeNode(10, new TreeNode(12, new TreeNode(8), new TreeNode(3)), new TreeNode(6, new TreeNode(1), null));
        TreeNode b = new TreeNode(10, new TreeNode(12, new TreeNode(8), null), new TreeNode(6));
        System.out.println(j.isSubStructure(a, b));
    }
}
