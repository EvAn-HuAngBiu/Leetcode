#include <iostream>
#include <queue>
#include <stack>
#include<cstdlib>
#include <climits>
#include <cstring>
#include<map>
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
    inline int max(int a, int b) {
        return a > b ? a : b;
    }
    int maxVal = INT_MIN;
    int loop(TreeNode* p) {
        if (!p) {
            return 0;
        }
        int l = loop(p->left), r = loop(p->right), m = max(l, r);
        int lv = (p->left ? p->left->val : INT_MIN), rv = (p->right ? p->right : INT_MAX);
        if (p->val > lv && p->val < rv) {
            maxVal = max(maxVal, m + p->val);
            return m + p->val;
        }
        return 0;
    }
    int maxSumBST(TreeNode *root)
    {
        loop(root);
        return maxVal;
    }
};

TreeNode* inputTree()
{
    int n,count=0;
    char item[100];
    cin>>n;
    if (n==0)
        return NULL;
    cin>>item;
    TreeNode* root = new TreeNode(atoi(item));
    count++;
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    while (count<n)
    {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        cin>>item;
        count++;
        if (strcmp(item,"null")!=0)
        {
            int leftNumber = atoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }
        if (count==n)
            break;
        cin>>item;
        count++;
        if (strcmp(item,"null")!=0)
        {
            int rightNumber = atoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main()
{
    TreeNode* root;
    root=inputTree();
    int res=Solution().maxSumBST(root);
    cout<<res;
}
