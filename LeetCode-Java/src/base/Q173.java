package base;

import java.util.ArrayList;
import java.util.List;

/**
 * Project: LeetCode-Java
 * File: Q173
 *
 * @author evan
 * @date 2021/3/28
 */
class BSTIterator {
    private List<Integer> list;
    private int index;

    private void loop(TreeNode p) {
        if (p != null) {
            loop(p.left);
            list.add(p.val);
            loop(p.right);
        }
    }

    public BSTIterator(TreeNode root) {
        list = new ArrayList<>();
        index = 0;
        loop(root);
    }

    public int next() {
        return list.get(index++);
    }

    public boolean hasNext() {
        return index < list.size();
    }
}

public class Q173 {
}
