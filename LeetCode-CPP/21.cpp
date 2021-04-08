#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode* head = new ListNode();
        ListNode* p = l1, *q = l2, *t = head;
        while (p && q) {
            if (p->val < q->val) {
                t->next = p;
                p = p->next;
            } else {
                t->next = q;
                q = q->next;
            }
            t = t->next;
        }
        if (p) {
            t->next = p;
        }
        if (q) {
            t->next = q;
        }
        return head->next;
    }
};

int main()
{
    return 0;
}