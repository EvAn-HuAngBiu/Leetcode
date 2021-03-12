#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<ListNode *> splitListToParts(ListNode *root, int k)
{
    int len = 0;
    ListNode* p = root, *q;
    while (p) {
        len++;
        p = p->next;
    }
    vector<int> split(k, len / k);
    int remain = len % k;
    for (int i = 0; i < remain; i++) {
        ++split[i];
    }
    vector<ListNode*> result(k);
    p = root;
    for (int i = 0; i < k; i++) {
        int count = split[i];
        if (!count) {
            break;
        }
        result[i] = p;
        q = p;
        for (int j = 0; j < count; j++) {
            if (j != 0) {
                q = q->next;
            }
            p = p->next;
        }
        q->next = nullptr;
    }
    return result;
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
    auto v = splitListToParts(head, 3);
    for (auto it : v) {
        display(it);
    }
    return 0;
}