package base;

import java.util.Arrays;
import java.util.Comparator;
import java.util.function.IntFunction;

/**
 * <p>
 * Project: LeetCode-Java
 * File: Q449
 *
 * @author evan
 * @date 2021/8/20
 */
class Codec {

    public String serialize(TreeNode p) {
        if (p == null) {
            return null;
        }
        StringBuilder result = new StringBuilder();
        result.append(p.val);
        String left = serialize(p.left), right = serialize(p.right);
        if (left != null) {
            result.append(",").append(left);
        }
        if (right != null) {
            result.append(",").append(right);
        }
        return result.toString();
    }

    private int[] preOrder;
    private int[] inOrder;

    private TreeNode buildTree(int preIdx, int inIdx, int len) {
        if (len == 0) {
            return null;
        } else if (len == 1) {
            return new TreeNode(preOrder[preIdx]);
        }

        TreeNode cur = new TreeNode(preOrder[preIdx]);
        int nextRoot = preOrder[preIdx], nextIn = inIdx;
        while (inOrder[nextIn] != nextRoot) {
            nextIn++;
        }

        cur.left = buildTree(preIdx + 1, inIdx, nextIn - inIdx);
        cur.right = buildTree(preIdx + nextIn - inIdx + 1, nextIn + 1, len - (nextIn - inIdx) - 1);
        return cur;
    }

    public TreeNode deserialize(String data) {
        if (data == null || data.length() == 0) {
            return null;
        }
        preOrder = Arrays.stream(data.split(",")).mapToInt(Integer::parseInt).toArray();
        inOrder = Arrays.stream(preOrder).sorted().toArray();
        return buildTree(0, 0, inOrder.length);
    }
}

public class Q449 {
    public static void main(String[] args) {
        Codec codec = new Codec();
        TreeNode root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

        String serialize = codec.serialize(root);
        System.out.println(serialize);

        TreeNode node = codec.deserialize("2,1");
    }
}
