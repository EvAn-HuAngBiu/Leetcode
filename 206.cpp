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

ListNode* reverseList(ListNode* head) {
    ListNode* nhead = new ListNode(0), *p = head, *q;
    while (p) {
        q = p;
        p = p->next;
        q->next = nhead->next;
        nhead->next = q;
    }
    return nhead->next;
}

int main()
{
    return 0;
}