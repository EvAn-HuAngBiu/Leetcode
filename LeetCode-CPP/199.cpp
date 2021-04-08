#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right = NULL) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        int size;
        queue<vector<TreeNode*>> q;
        vector<TreeNode*> cur;
        cur.emplace_back(root);
        q.push(cur);
        vector<int> result;
        while (!q.empty()) {
            vector<TreeNode*> last = q.front();
            q.pop();
            result.emplace_back(last.back()->val);
            vector<TreeNode*> next;
            size = last.size();
            last.emplace_back(nullptr);
            for (int i = 0; i < size; ++i) {
                if (last[i]->left) {
                    next.emplace_back(last[i]->left);
                }
                if (last[i]->right) {
                    next.emplace_back(last[i]->right);
                }
            }
            if (!next.empty()) {
                q.push(next);
            }
        }
        return result;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1, new TreeNode(2, NULL, new TreeNode(5, new TreeNode(6))), new TreeNode(3, new TreeNode(4)));
    auto result = Solution().rightSideView(root);
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}