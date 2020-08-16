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
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (!head) {
            return nullptr;
        } else if (!head->next || m == n) {
            return head;
        }
        ListNode* root = new ListNode(0, head);
        ListNode* p = root, *q, *r, *last;
        for (int i = 0; i < m - 1; ++i) {
            p = p->next;
        }
        q = p->next;
        last = q;
        p->next = nullptr;
        for (int i = 0; i <= n - m; ++i) {
            r = q->next;
            q->next = p->next;
            p->next = q;
            q = r;
        }
        last->next = r;
        return root->next;
    }
};

int main()
{
//    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5,
//                                                                                                  new ListNode(6, new ListNode(7, new ListNode(8))))))));
//    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* head = new ListNode(1, new ListNode(2));
    ListNode* p = Solution().reverseBetween(head, 1, 2);
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}