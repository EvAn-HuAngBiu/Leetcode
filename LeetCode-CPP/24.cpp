#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void swap(ListNode* prior, ListNode* cur, ListNode* next) {
    prior->next = next;
    cur->next = next->next;
    next->next = cur;
}

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* p = head, *q = head->next, *r;
    p->next = q->next;
    q->next = p;
    head = q;
    p = p->next;
    if (!p) {
        return head;
    }
    q = p->next;
    r = head->next;
    while (p && q) {
        swap(r, p, q);
        r = p;
        p = p->next;
        if (!p) {
            break;
        }
        q = p->next;
    }
    return head;
}

void display(ListNode* head) {
    ListNode* p = head;
    while (p) {
        cout << p->val;
        p = p->next;
        if (p) {
            cout << "->";
        }
    }
    cout << endl;
}

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for (int i = 2; i <= 2; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    display(swapPairs(head));
    return 0;
}