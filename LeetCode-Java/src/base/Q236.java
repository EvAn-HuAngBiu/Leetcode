package base;

import java.util.*;

/**
 * Project: LeetCode-Java
 * File: Q236
 *
 * @author evan
 * @date 2021/8/18
 */
public class Q236 {
    public static TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        LinkedList<TreeNode> pPath = new LinkedList<>(), qPath = new LinkedList<>();
        pPath.addLast(root);
        qPath.addLast(root);
        loop(pPath, root, p);
        loop(qPath, root, q);
        ListIterator<TreeNode> pIter = pPath.listIterator(), qIter = qPath.listIterator();
        while (pIter.hasNext() && qIter.hasNext()) {
            if (pIter.next() != qIter.next()) {
                pIter.previous();
                return pIter.previous();
            }
        }

        return pIter.hasNext() ? qIter.previous() : pIter.previous();
    }

    public static boolean loop(LinkedList<TreeNode> path, TreeNode cur, TreeNode target) {
        if (cur == null) {
            return false;
        }
        if (cur == target) {
            return true;
        }
        if (cur.left != null) {
            path.addLast(cur.left);
            boolean left = loop(path, cur.left, target);
            if (left) {
                return true;
            } else {
                path.removeLast();
            }
        }

        if (cur.right != null) {
            path.addLast(cur.right);
            boolean right = loop(path, cur.right, target);
            if (right) {
                return true;
            } else {
                path.removeLast();
            }
        }

        return false;
    }

    // 利用结点值不一样这个特点，构造一个val到结点的哈希表，即类似并查集的结构
    public static Map<Integer, TreeNode> map = new HashMap<>();

    public static void preOrder(TreeNode node) {
        if (node.left != null) {
            map.put(node.left.val, node);
            preOrder(node.left);
        }

        if (node.right != null) {
            map.put(node.right.val, node);
            preOrder(node.right);
        }
    }

    public static TreeNode lowestCommonAncestor2(TreeNode root, TreeNode p, TreeNode q) {
        // 先扫描一遍，构造路径
        preOrder(root);
        Set<Integer> path = new HashSet<>();
        TreeNode cur = p;
        while (cur != root) {
            path.add(cur.val);
            cur = map.get(cur.val);
        }
        path.add(root.val);

        cur = q;
        while (!path.contains(cur.val)) {
            cur = map.get(cur.val);
        }
        return cur;
    }

    public static void main(String[] args) {
        TreeNode q = new TreeNode(4);
        TreeNode t = new TreeNode(1, new TreeNode(6), new TreeNode(8));
        TreeNode p = new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), q));
        TreeNode root = new TreeNode(3, p, t);
        // TreeNode p = new TreeNode(2);
        // TreeNode root = new TreeNode(1, p, null);
        System.out.println(lowestCommonAncestor2(root, p, q).val);
    }
}
