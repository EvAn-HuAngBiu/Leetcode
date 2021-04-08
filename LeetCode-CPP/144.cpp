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

class Solution {
public:
    vector<int> v;
    void preOrder(TreeNode* p) {
        if (p) {
            v.emplace_back(p->val);
            preOrder(p->left);
            preOrder(p->right);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return v;
    }
};

int main()
{
    return 0;
}