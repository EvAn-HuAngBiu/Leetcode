#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
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
    inline int max(int a, int  b) {
        return a > b ? a : b;
    }

    int rob1(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int cur = root->val;
        if (root->left) {
            cur += rob1(root->left->left) + rob1(root->left->right);
        }
        if (root->right) {
            cur += rob1(root->right->left) + rob1(root->right->right);
        }
        return max(cur, rob1(root->left) + rob1(root->right));
    }

    map<long, int> store;
    int robHelper(TreeNode* p, long index) {
        if (!p) {
            return 0;
        }
        if (store.find(index) != store.end()) {
            return store[index];
        }
        int cur = p->val;
        if (p->left) {
            cur += robHelper(p->left->left, index * 2 * 2) + robHelper(p->left->right, index * 2 * 2 + 1);
        }
        if (p->right) {
            cur += robHelper(p->right->left, (index * 2 + 1) * 2) + robHelper(p->right->right, (index * 2 + 1) * 2 + 1);
        }
        cur = max(cur, robHelper(p->left, index * 2) + robHelper(p->right, index * 2 + 1));
        store[index] = cur;
        return cur;
    }

    int rob2(TreeNode* root) {
        return robHelper(root, 1);
    }

    int* robHelper(TreeNode* p) {
        if (!p) {
            return new int[2]{0, 0};
        }
        int* result = new int[2]{0, 0};
        int* left = robHelper(p->left);
        int* right = robHelper(p->right);
        
        result[0] = max(left[0], left[1]) + max(right[0], right[1]);
        result[1] = p->val + left[0] + right[0];
        return result;
    }

    int rob(TreeNode* root) {
        int* result = robHelper(root);
        return max(result[0], result[1]);
    }
};

int main()
{
    return 0;
}