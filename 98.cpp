#include <iostream>
#include <queue>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <map>
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
    stack<int> result;
    bool flag = true;
    void inOrder(TreeNode* p) {
        if (!p || !flag) {
            return;
        }
        inOrder(p->left);
        if (!result.empty() && result.top() >= p->val) {
            flag = false;
            return;
        }
        result.push(p->val);
        inOrder(p->right);
    }
    bool isValidBST(TreeNode *root)
    {
        inOrder(root);
        return flag;
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
    bool res=Solution().isValidBST(root);
    cout<<(res?"true":"false")<<endl;
}