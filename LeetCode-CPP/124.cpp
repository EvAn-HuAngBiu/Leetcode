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

class Solution {
public:
    inline int max(int a, int b) {
        return a > b ? a : b;
    }

    int maxValue = INT_MIN;
    int dfs(TreeNode* p) {
        if (!p) {
            return 0;
        }
        int left = max(dfs(p->left), 0);
        int right = max(dfs(p->right), 0);
        maxValue = max(maxValue, left + right + p->val);
        return max(left, right) + p->val;
    }


    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxValue;
    }
};

int main()
{
    TreeNode* root;
    root=inputTree();
    int res=Solution().maxPathSum(root);
    cout<<res<<endl;
}