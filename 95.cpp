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

vector<TreeNode*> buildTree(int beg, int end) {
    if (beg > end) {
        return {nullptr};
    }
    vector<TreeNode*> result;
    for (int i = beg; i <= end; i++) {
        vector<TreeNode*> left = buildTree(beg, i - 1);
        vector<TreeNode*> right = buildTree(i + 1, end);
        for (auto& l : left) {
            for (auto& r : right) {
                TreeNode* cur = new TreeNode(i);
                cur->left = l;
                cur->right = r;
                result.emplace_back(cur);
            }
        }
    }
    return result;
}

vector<TreeNode *> generateTrees(int n)
{
    if (!n) {
        return vector<TreeNode*>();
    }
    return buildTree(1, n);
}

TreeNode* transfer(TreeNode* node, int offset) {
    if (!node) {
        return nullptr;
    }
    TreeNode* cur = new TreeNode(offset + node->val);
    cur->left = transfer(node->left, offset);
    cur->right = transfer(node->right, offset);
    return cur;
}

vector<TreeNode *> generateTrees2(int n)
{
    if (!n) {
        return vector<TreeNode*>();
    }
    vector<vector<TreeNode*>> dp(n + 1, vector<TreeNode*>());
    dp[0].emplace_back(nullptr);
    for (int len = 1; len <= n; len++) {
        for (int root = 1; root <= n; root++) {
            int l = root - 1, r = len - root;
            for (auto& left : dp[l]) {
                for (auto& right : dp[r]) {
                    TreeNode* cur = new TreeNode(root);
                    cur->left = left;
                    cur->right = transfer(right, root);
                    dp[len].emplace_back(cur);
                }
            }
        }
    }
    return dp[n];
}

int main()
{
    generateTrees(3);
    return 0;
}