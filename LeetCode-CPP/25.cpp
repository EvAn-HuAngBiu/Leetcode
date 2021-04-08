#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode* head) {
    ListNode* p = head;
    while (p) {
        if (p != head) {
            cout << "->";
        }
        cout << p->val;
        p = p->next;
    }
    cout << endl;
}

ListNode* reverse(ListNode* head, int k) {
    ListNode* p = head, *s = head;
    ListNode* r = new ListNode(0);
    for (int i = 0; i < k; i++) {
        s = s->next;
        p->next = r->next;
        r->next = p;
        p = s;
        if (!s) {
            return r->next;
        }
    }
    return r->next;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* p = head, *q = head;
    int len = 0;
    while (p) {
        p = p->next;
        len++;
    }
    if (len < k) {
        return head;
    }
    for (int i = 0; i < k; i++) {
        q = q->next;
    }
    head = reverse(head, k);
    if (len == k) {
        return head;
    }
    p = head;
    for (int i = 0; i < k - 1; i++) {
        p = p->next;
    }
    p->next = q;
    for (int i = 1; i < len / k; i++) {
        q = p->next;
        for (int j = 0; j < k; j++) {
            q = q->next;
        }
        p->next = reverse(p->next, k);
        for (int j = 0; j < k; j++) {
            p = p->next;
        }
        p->next = q;
    }
    return head;
}

int main()
{
    ListNode* head = new ListNode(1), *p = head;
    for (int i = 2; i <= 2; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    print(reverseKGroup(head, 2));
//    reverseKGroup(head, 3);
    return 0;
}