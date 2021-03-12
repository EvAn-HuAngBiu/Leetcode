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

ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* p = head, *q;
    int sum;
    while (p) {
        q = p;
        sum = 0;
        while (q) {
            sum += q->val;
            if (sum == 0) {
                if (p == head) {
                    head = q->next;
                } else {
                    p->next = q->next;
                }
                return removeZeroSumSublists(head);
            }
            q = q->next;
        }
        p = p->next;
    }
    return head;
}

int main()
{
    ListNode* head = new ListNode(1), *p = head;
    int array[] = {2,3,-3,4};
    for (int i : array) {
        p->next = new ListNode(i);
        p = p->next;
    }
    print(removeZeroSumSublists(head));
    return 0;
}