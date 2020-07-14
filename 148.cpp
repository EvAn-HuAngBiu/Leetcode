#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* p = head->next, *q = head;
    while (p && p->next) {
        q = q->next;
        p = p->next->next;
    }
    ListNode* rightHead = q->next;
    q->next = nullptr;
    ListNode* left = sortList(head), *right = sortList(rightHead);
    ListNode* sorted = new ListNode(-1);
    p = left;
    q = right;
    ListNode* r = sorted;
    while (p && q) {
        if (p->val < q->val) {
            r->next = p;
            p = p->next;
        } else {
            r->next = q;
            q = q->next;
        }
        r = r->next;
        r->next = nullptr;
    }
    if (p) {
        r->next = p;
    }
    if (q) {
        r->next = q;
    }
    return sorted->next;
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
    ListNode* head = new ListNode(-1);
    ListNode* p = head;
    int array[] = {5, 3, 4, 0};
    for (int i : array) {
        p->next = new ListNode(i);
        p = p->next;
    }
    display(sortList(head));
    return 0;
}