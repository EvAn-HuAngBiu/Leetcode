#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    TreeNode *create(const vector<ListNode *> &nums, int begin, int end)
    {
        if (begin > end)
        {
            return nullptr;
        }
        if (begin == end)
        {
            return new TreeNode(nums[begin]->val);
        }
        int mid = (begin + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]->val);
        root->left = create(nums, begin, mid - 1);
        root->right = create(nums, mid + 1, end);
        return root;
    }

    // 方法1：空间换时间，利用数组存储链表中的每一个结点，时间复杂度O(N)，空间复杂度O(N)
    TreeNode *sortedListToBST1(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        vector<ListNode*> v;
        ListNode* p = head;
        while (p) {
            v.emplace_back(p);
            p = p->next;
        }
        return create(v, 0, v.size() - 1);
    }

    // 方法2：利用中序遍历，中序遍历过程中只记录当前应该取的结点下标，但并不真正的取数，直到
    // 当前节点已经到达了链表对应的位置时才取数（树最左边对应链表第一个元素，接着向上回溯的一个元素
    // 就是链表中的下一个元素，依次推移），在中序遍历中不断推移链表下标并构造树
    int len(ListNode* head) {
        ListNode* p = head;
        int cnt = 0;
        while (p) {
            ++cnt;
            p = p->next;
        }
        return cnt;
    }

    ListNode* head;
    TreeNode* inOrder(int begin, int end) {
        if (begin > end) {
            return nullptr;
        }
        int mid = begin + (end - begin) / 2;
        TreeNode* left = inOrder(begin, mid - 1);
        TreeNode* cur = new TreeNode(head->val);
        head = head->next;
        TreeNode* right = inOrder(mid + 1, end);
        cur->left = left;
        cur->right = right;
        return cur;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        this->head = head;
        int size = len(head);
        return inOrder(0, size - 1);
    }
};

int main()
{
    return 0;
}