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

class Solution {
public:
    inline int max(int a, int b) {
        return a > b ? a : b;
    }

    bool len(TreeNode* p, int &height) {
        if (!p) {
            height = -1;
            return true;
        }
        int left, right;
        if (len(p->left, left) && len(p->right, right) && abs(left - right) <= 1) {
            height = max(left, right) + 1;
            return true;
        }
        return false;
    }

    bool isBalanced(TreeNode* root) {
        int height;
        return len(root, height);
    }
};

int main()
{
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout << boolalpha << Solution().isBalanced(root) << endl;
    return 0;
}