package base;

import java.util.*;

/**
 * Project: LeetCode-Java
 * File: Q652
 *
 * @author evan
 * @date 2021/8/18
 */
public class Q652 {
    public static Map<String, Integer> counter;
    public static List<TreeNode> result;

    public static List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        counter = new HashMap<>();
        result = new LinkedList<>();
        levelOrder(root);
        return result;
    }

    public static String levelOrder(TreeNode root) {
        if (root == null) {
            return "#";
        }
        String curTree = root.val + "," + levelOrder(root.left) + "," + levelOrder(root.right);
        counter.put(curTree, counter.getOrDefault(curTree, 0) + 1);
        if (counter.get(curTree) == 2) {
            result.add(root);
        }
        return curTree;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1, new TreeNode(2, new TreeNode(4), null),
                new TreeNode(3, new TreeNode(2, new TreeNode(4), null), new TreeNode(4)));
        for (TreeNode t : findDuplicateSubtrees(root)) {
            System.out.println(t.val);
        }
    }
}
