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

ListNode* oddEvenList(ListNode* head) {
    ListNode* odd = new ListNode(0), *even = new ListNode(0);
    ListNode* p = odd, *q = even;
    ListNode* r = head;
    int cnt = 1;
    while (r) {
        if (cnt % 2) {
            p->next = r;
            p = p->next;
        } else {
            q->next = r;
            q = q->next;
        }
        r = r->next;
        cnt++;
        p->next = q->next = nullptr;
    }
    p->next = even->next;
    return odd->next;
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
    for (int i = 2; i <= 10; i++) {
        ListNode* q = new ListNode(i);
        p->next = q;
        p = q;
    }
    display(oddEvenList(head));
    return 0;
}