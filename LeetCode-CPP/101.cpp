#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
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
    bool judge(const TreeNode* l, const TreeNode* r)
    {
        if (!l && !r) {
            return true;
        }
        if (!l || !r) {
            return false;
        }
        if (l->val == r->val) {
            return judge(l->left, r->right) && judge(l->right, r->left);
        }
        return false;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root) {
            return true;
        }
        return judge(root->left, root->right);
    }
};

int main()
{
    TreeNode *root;
    root = inputTree();
    bool res = Solution().isSymmetric(root);
    cout << (res ? "true" : "false");
}