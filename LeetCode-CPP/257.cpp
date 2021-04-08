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
    TreeNode(int x, TreeNode* l) : val(x), left(l), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution
{
public:
    vector<vector<int>> result;
    void dfs(TreeNode* p, vector<int>& cur) {
        if (!p->left && !p->right) {
            result.emplace_back(vector<int>(cur));
            return;
        }
        if (p->left) {
            cur.emplace_back(p->left->val);
            dfs(p->left, cur);
            cur.pop_back();
        }
        if (p->right) {
            cur.emplace_back(p->right->val);
            dfs(p->right, cur);
            cur.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root)
    {
        if (!root) {
            return {};
        }
        vector<int> v;
        v.emplace_back(root->val);
        dfs(root, v);
        vector<string> s;
        for (auto& v : result) {
            string cur;
            for (int i = 0; i < v.size(); ++i) {
                if (i) {
                    cur += "->";
                }
                cur += to_string(v[i]);
            }
            s.emplace_back(cur);
        }
        return s;
    }
};

int main()
{
    return 0;
}