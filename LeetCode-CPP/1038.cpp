#include <iostream>
#include <queue>
#include <stack>
#include<cstdlib>
#include <cstring>
#include<map>
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
    int sum = 0;
    void inOrder(TreeNode* p) {
        if (p) {
            inOrder(p->right);
            p->val += sum;
            sum = p->val;
            inOrder(p->left);
        }
    }

    TreeNode *bstToGst(TreeNode *root)
    {
        if (!root) {
            return nullptr;
        }
        inOrder(root);
        return root;
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

void printTree(TreeNode* root) {
    if (root == NULL) {
      return;
    }
    bool isFirst=true;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node == NULL) {
          continue;
        }
        if (!isFirst)
            cout<<",";
        cout<<node->val;
        isFirst=false;
        q.push(node->left);
        q.push(node->right);
    }
}

int main()
{
    TreeNode* root;
    root=inputTree();
    TreeNode* res=Solution().bstToGst(root);
    printTree(res);
}