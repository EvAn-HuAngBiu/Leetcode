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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode* pre, *p1, *p2;
    void inOrder(TreeNode* p) {
        if (!p) {
            return;
        }
        inOrder(p->left);
        if (!pre && pre->val > p->val) {
            if (!p1) {
                p1 = pre;
            }
            p2 = p;
        }
        pre = p;
        inOrder(p->right);
    }

    void recoverTree(TreeNode *root)
    {
        if (!root) {
            return;
        }
        pre = nullptr;
        inOrder(root);
        int temp = p1->val;
        p1->val = p2->val;
        p2->val = temp;
    }
};

int main()
{
    return 0;
}