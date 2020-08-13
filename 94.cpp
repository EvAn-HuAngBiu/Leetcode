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
private:
    vector<int> result;
public:
    void inOrder(TreeNode* p) {
        if (p) {
            inOrder(p->left);
            result.emplace_back(p->val);
            inOrder(p->right);
        }
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        inOrder(root);
        return result;
    }
};

int main()
{
    return 0;
}