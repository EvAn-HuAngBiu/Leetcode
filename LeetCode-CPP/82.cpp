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
    ListNode(int x, ListNode* p) : val(x), next(p) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head) {
            return nullptr;
        }
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* pre = root, *p = root->next;
        while (p) {
            while (p->next && p->next->val == p->val) {
                p = p->next;
            }
            if (pre->next == p) {
                pre = p;
                p = p->next;
            } else {
                pre->next = p->next;
                p = p->next;
            }
        }
        return root->next;
    }
};

int main()
{
    ListNode* head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(4)))))));
    ListNode* p = head;
    p = Solution().deleteDuplicates(head);
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}