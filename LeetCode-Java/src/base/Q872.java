package base;

import java.util.ArrayList;
import java.util.List;

/**
 * Project: LeetCode-Java
 * File: Q872
 *
 * @author evan
 * @date 2021/5/10
 */
public class Q872 {
    private List<Integer> list1, list2;

    private void preOrder(List<Integer> list, TreeNode p) {
        if (p.left == null && p.right == null) {
            list.add(p.val);
            return;
        }
        if (p.left != null) {
            preOrder(list, p.left);
        }
        if (p.right != null) {
            preOrder(list, p.right);
        }
    }

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        list1 = new ArrayList<>();
        list2 = new ArrayList<>();
        preOrder(list1, root1);
        preOrder(list2, root2);
        return list1.equals(list2);
    }

    public static void main(String[] args) {
        TreeNode t1 = new TreeNode(3,
                new TreeNode(5, new TreeNode(6), new TreeNode(7)),
                new TreeNode(1, new TreeNode(4), new TreeNode(2,
                        new TreeNode(9), new TreeNode(11, new TreeNode(8), new TreeNode(10)))));
        TreeNode t2 = new TreeNode(3,
                new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4))),
                new TreeNode(1, new TreeNode(9), new TreeNode(8)));

        System.out.println(new Q872().leafSimilar(t1, t2));
    }
}
