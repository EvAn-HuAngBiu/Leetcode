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

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) {
            return nullptr;
        }
        ListNode* left = new ListNode(0), *p = left;
        ListNode* right = new ListNode(0), *q = right;
        ListNode* r = head;
        while (r) {
            if (r->val < x) {
                p->next = r;
                p = p->next;
            } else {
                q->next = r;
                q = q->next;
            }
            r = r->next;
        }
        if (!left->next) {
            return right->next;
        } else if (!right->next) {
            return left->next;
        }
        p->next = right->next;
        q->next = nullptr;
        return left->next;
    }
};

int main()
{
    ListNode* head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2, new ListNode(1)))))));
    ListNode* p = head;
    p = Solution().partition(head, 3);
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}