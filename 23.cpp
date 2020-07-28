#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
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
    struct cmp {
        bool operator()(const ListNode * a, const ListNode * b) {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int size = lists.size();
        if (!size)
        {
            return nullptr;
        }
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        ListNode* head = new ListNode(0), *p, *q = head;
        for (ListNode* cur : lists) {
            if (cur) {
                pq.push(cur);
            }
        }
        while (pq.size() > 1) {
            p = pq.top();
            pq.pop();
            q->next = p;
            q = p;
            p = p->next;
            if (p) {
                pq.push(p);
            }
        }
        if (pq.size() == 1) {
            q->next = pq.top();
        }
        return head->next;
    }
};

int main()
{
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));
    vector<ListNode*> v = {l1, l2, l3};
    ListNode* p = Solution().mergeKLists(v);
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
    // vector<ListNode*> v2 = {nullptr, nullptr};
    // Solution().mergeKLists(v2);
    return 0;
}