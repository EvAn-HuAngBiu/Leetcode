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
    vector<TreeNode*> v;
    void preOrder(TreeNode* p) {
        if (p) {
            v.emplace_back(p);
            preOrder(p->left);
            preOrder(p->right);
        }
    }

    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        preOrder(root);
        TreeNode* head = new TreeNode(0), *tail = head;
        for (TreeNode* p : v) {
            tail->right = p;
            tail = tail->right;
        }
        root = head->right;
        root->left = nullptr;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, nullptr, new TreeNode(6)));
    Solution().flatten(root);
    TreeNode* p = root;
    while (p) {
        cout << p->val << endl;
        p = p->right;
    }
    return 0;
}