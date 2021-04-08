package base;

public class J07 {
    private TreeNode rebuild(int[] pre, int[] in, int preIdx, int inBeg, int inEnd) {
        if (inBeg > inEnd) {
            return null;
        }
        TreeNode cur = new TreeNode(pre[preIdx]);
        int idx = inBeg;
        while (idx <= inEnd) {
            if (in[idx] == pre[preIdx]) {
                break;
            }
            ++idx;
        }
        cur.left = rebuild(pre, in, preIdx + 1, inBeg, idx - 1);
        cur.right = rebuild(pre, in, preIdx + (idx - inBeg) + 1, idx + 1, inEnd);
        return cur;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return rebuild(preorder, inorder, 0, 0, inorder.length - 1);
    }

    public static void main(String[] args) {
        J07 j = new J07();
        // int[] pre = {3, 9, 20, 15, 7};
        // int[] in = {9, 3, 15, 20, 7};
        int[] pre = {1, 2, 4, 8, 5, 9, 3, 6, 10, 7, 11};
        int[] in = {8, 4, 2, 5, 9, 1, 10, 6, 3, 7, 11};
        TreeNode t = j.buildTree(pre, in);
    }
}
