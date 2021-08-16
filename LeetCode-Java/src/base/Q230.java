package base;

import java.util.*;

/**
 * Project: LeetCode-Java
 * File: Q230
 *
 * @author evan
 * @date 2021/8/16
 */
public class Q230 {
    private List<Integer> result = new LinkedList<>();

    public void inOrder(TreeNode p) {
        if (p == null) {
            return;
        }
        inOrder(p.left);
        result.add(p.val);
        inOrder(p.right);
    }

    public int kthSmallest(TreeNode root, int k) {
        inOrder(root);
        return result.get(k - 1);
    }

    private static int result2 = -1;
    public static int inOrder2(TreeNode p, int cur, int k) {
        if (cur <= 0) {
            return Integer.MIN_VALUE;
        }
        if (p == null) {
            return cur;
        }
        int left = inOrder2(p.left, cur, k);
        if (left == k) {
            result2 = p.val;
            return Integer.MIN_VALUE;
        }
        left = left + 1;
        return inOrder2(p.right, left, k);
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), null), new TreeNode(4)), new TreeNode(6));
        inOrder2(root, 1, 1);
        System.out.println(result2);
    }
}
