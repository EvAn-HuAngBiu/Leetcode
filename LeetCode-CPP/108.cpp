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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode* create(const vector<int>& nums, int begin, int end) {
        if (begin > end) {
            return nullptr;
        }
        if (begin == end) {
            return new TreeNode(nums[begin]);
        }
        int mid = (begin + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = create(nums, begin, mid - 1);
        root->right = create(nums, mid + 1, end);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return create(nums, 0, nums.size() - 1);
    }
};

int main()
{
    return 0;
}