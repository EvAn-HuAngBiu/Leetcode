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
};

class Solution
{
public:
    int len(TreeNode* p) {
        if (!p) {
            return 0;
        }
        return min(len(p->left), len(p->right)) + 1;
    }

    int minDepth(TreeNode *root)
    {
        if (!root) {
            return 0;
        }
        if (root->left && root->right) {
            return min(minDepth(root->right), minDepth(root->left)) + 1;
        } else if (!root->left) {
            return minDepth(root->right) + 1;
        } else {
            return minDepth(root->left + 1);
        }
    }
};

int main()
{
    return 0;
}