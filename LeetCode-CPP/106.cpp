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
    TreeNode* createTree(const vector<int>& post, const vector<int>& in, int inBeg, int inEnd, int postEnd) {
        if (inBeg > inEnd) {
            return nullptr;
        } else if (inBeg == inEnd) {
            return new TreeNode(post[postEnd]);
        }
        TreeNode* root = new TreeNode(post[postEnd]);
        int index;
        for (int i = inBeg; i <= inEnd; ++i) {
            if (in[i] == post[postEnd]) {
                index = i;
                break;
            }
        }
        root->left = createTree(post, in, inBeg, index - 1, postEnd - (inEnd - index) - 1);
        root->right = createTree(post, in, index + 1, inEnd, postEnd - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return createTree(postorder, inorder, 0, inorder.size() - 1, postorder.size() - 1);
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
    vector<int> post = {9,15,7,20,3};
    vector<int> in = {9,3,15,20,7};
    TreeNode* p = Solution().buildTree(post, in);
    inOrder(p);
    return 0;
}