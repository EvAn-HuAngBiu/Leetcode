#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle1(ListNode *head)
    {
        unordered_set<ListNode *> s;
        ListNode *p = head;
        while (p)
        {
            if (s.find(p) == s.end())
            {
                s.insert(p);
            }
            else
            {
                return true;
            }
            p = p->next;
        }
        return false;
    }

    bool hasCycle(ListNode* head) {
        ListNode* p = head, *q = head->next;
        while (p != q) {
            if (!p || !q || !q->next) {
                return false;
            }
            p = p->next;
            q = q->next->next;
        }
        return true;
    }
};

int main()
{
    return 0;
}