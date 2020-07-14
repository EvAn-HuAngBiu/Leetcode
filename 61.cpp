#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head) {
        return head;
    }
    ListNode* p = head;
    ListNode* q = nullptr;
    int len = 0;
    while (p) {
        q = p;
        p = p->next;
        len++;
    }
    q->next = head;
    int begin = len - (k % len);
    p = head;
    q = nullptr;
    for (int i = 0; i < begin; i++) {
        q = p;
        p = p->next;
    }
    q->next = nullptr;
    return p;
}

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

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    for (int i = 1; i <= 2; i++) {
        ListNode* q = new ListNode(i);
        p->next = q;
        p = q;
    }
    print(rotateRight(head, 4));
    return 0;
}