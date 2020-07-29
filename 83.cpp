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
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode* pre = head, *cur = head->next, *del;
        while (cur) {
            if (cur->val == pre->val) {
                del = cur;
                cur = cur->next;
                pre->next = cur;
                delete del;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

int main()
{
    ListNode* head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
    ListNode* p = Solution().deleteDuplicates(head);
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}