#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution
{
public:
    TreeNode* createTree(const vector<int>& pre, const vector<int>& in, int inBeg, int inEnd, int preBeg) {
        if (inBeg > inEnd) {
            return nullptr;
        } else if (inBeg == inEnd) {
            return new TreeNode(pre[preBeg]);
        }
        TreeNode* root = new TreeNode(pre[preBeg]);
        int index;
        for (int i = inBeg; i <= inEnd; ++i) {
            if (in[i] == pre[preBeg]) {
                index = i;
                break;
            }
        }
        root->left = createTree(pre, in, inBeg, index - 1, preBeg + 1);
        root->right = createTree(pre, in, index + 1, inEnd, preBeg + index - inBeg + 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return createTree(preorder, inorder, 0, inorder.size() - 1, 0);
    }
};

void inOrder(TreeNode* p) {
    if (p) {
        inOrder(p->left);
        cout << p->val << " ";
        inOrder(p->right);
    }
}

int main()
{
    vector<int> pre = {3,9,20,15,7};
    vector<int> in = {9,3,15,20,7};
    TreeNode* p = Solution().buildTree(pre, in);
    inOrder(p);
    return 0;
}