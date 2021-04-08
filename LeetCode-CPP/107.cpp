#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *inputTree()
{
    int n, count = 0;
    char item[100];
    cin >> n;
    if (n == 0)
        return NULL;
    cin >> item;
    TreeNode *root = new TreeNode(atoi(item));
    count++;
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    while (count < n)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();
        cin >> item;
        count++;
        if (strcmp(item, "null") != 0)
        {
            int leftNumber = atoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }
        if (count == n)
            break;
        cin >> item;
        count++;
        if (strcmp(item, "null") != 0)
        {
            int rightNumber = atoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (!root) {
            return {};
        }
        int cur = 1, next = 0;
        queue<TreeNode*> q;
        vector<vector<int>> result;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            for (int i = 0; i < cur; i++) {
                TreeNode* p = q.front();
                q.pop();
                level.emplace_back(p->val);
                if (p->left) {
                    ++next;
                    q.push(p->left);
                }
                if (p->right) {
                    ++next;
                    q.push(p->right);
                }
            }
            result.emplace(result.begin(), level);
            cur = next;
            next = 0;
        }
        return result;
    }
};

int main()
{
    TreeNode *root;
    root = inputTree();
    vector<vector<int>> res = Solution().levelOrderBottom(root);
    for (int i = 0; i < res.size(); i++)
    {
        vector<int> v = res[i];
        for (int j = 0; j < v.size(); j++)
            cout << v[j] << " ";
    }
}