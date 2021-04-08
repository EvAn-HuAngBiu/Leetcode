#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        TreeNode *cur, *pre = nullptr;
        vector<int> result;
        stack<TreeNode *> S;
        // 将根结点入栈保存
        S.push(root);
        while (!S.empty())
        {
            cur = S.top();
            if ((!cur->left && !cur->right) ||
                (pre && (pre == cur->left || pre == cur->right)))
            {
                result.emplace_back(cur->val);
                S.pop();
                pre = cur;
            }
            else
            {
                if (cur->right)
                {
                    S.push(cur->right);
                }
                if (cur->left)
                {
                    S.push(cur->left);
                }
            }
        }
    }
};

int main()
{
    return 0;
}