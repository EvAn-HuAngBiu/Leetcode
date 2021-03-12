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
    void dfs(TreeNode* p, vector<int>& cur, int target, int sum) {
        if (target == sum) {
            result.emplace_back(vector<int>(cur));
        }
        cur.emplace_back(p->val);
        if (p->left) {
            dfs(p->left, cur, target, sum + p->val);
        }
        if (p->right) {
            dfs(p->right, cur, target, sum + p->val);
        }
        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (!root) {
            return {};
        }
        vector<int> v;
        dfs(root, v, sum, 0);
        return result;
    }
};

int main()
{
    TreeNode* root = new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2))), new TreeNode(8, new TreeNode(13), new TreeNode(4, new TreeNode(5), new TreeNode(1))));
    auto result = Solution().pathSum(root, 22);
    for (auto& v : result) {
        for (auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}