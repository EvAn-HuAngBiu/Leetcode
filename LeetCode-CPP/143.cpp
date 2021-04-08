#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    if (!head) {
        return;
    }
    int len = 0;
    ListNode* p = head, *q = head;
    while (p) {
        p = p->next;
        len++;
        if (len % 2 == 0) {
            q = q->next;
        }
    }
    ListNode* r = q->next;
    q->next = nullptr;
    q = r;
    p = new ListNode(0);
    while (r) {
        r = r->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    r = p->next;
    delete p;
    q = r;
    ListNode* s = q;
    p = head;
    while (q) {
        q = q->next;
        s->next = p->next;
        p->next = s;
        p = p->next->next;
        s = q;
    }
}

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for (int i = 2; i <= 9; i++) {
        ListNode* q = new ListNode(i);
        p->next = q;
        p = q;
    }
    reorderList(head);
    return 0;
}