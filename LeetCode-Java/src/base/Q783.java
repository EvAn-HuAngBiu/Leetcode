package base;

import java.util.HashSet;
import java.util.Set;

/**
 * Project: LeetCode-Java
 * File: Q783
 *
 * @author evan
 * @date 2021/4/13
 */
public class Q783 {
    private int min = Integer.MAX_VALUE;
    private final Set<Integer> values = new HashSet<>();

    private void preOrder(TreeNode cur) {
        if (cur == null) {
            return;
        }
        if (!values.contains(cur.val)) {
            values.forEach(v -> min = Math.min(min, Math.abs(cur.val - v)));
            values.add(cur.val);
        }
        preOrder(cur.left);
        preOrder(cur.right);
    }

    public int minDiffInBST(TreeNode root) {
        preOrder(root);
        return min;
    }

    public static void main(String[] args) {

    }
}
