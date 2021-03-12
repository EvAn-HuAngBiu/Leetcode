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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* p = headA, *q = headB;
        if (!p || !q) {
            return nullptr;
        }
        bool pa = true, qb = true;
        while (p != q) {
            if (p->next) {
                p = p->next;
            } else if (pa) {
                p = headB;
                pa = !pa;
            } else {
                return nullptr;
            }

            if (q->next) {
                q = q->next;
            } else if (qb) {
                q = headA;
                qb = !qb;
            } else {
                return nullptr;
            }
        }
        return p;
    }
};

int main()
{
    return 0;
}