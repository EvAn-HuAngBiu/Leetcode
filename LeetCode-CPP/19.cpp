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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) {
            return nullptr;
        }
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* p = root, *q = root;
        for (int i = 0; i < n; i++) {
            q = q->next;
        }
        while (q->next) {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return root->next;
    }
};

int main()
{
    ListNode* head = new ListNode(1, new ListNode(2));
    ListNode* p = Solution().removeNthFromEnd(head, 2);
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}