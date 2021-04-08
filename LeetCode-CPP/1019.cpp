#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int findNext(ListNode* p) {
    ListNode* q = p->next;
    int max = p->val;
    while (q) {
        if (q->val > max) {
            return q->val;
        }
        q = q->next;
    }
    return 0;
}

vector<int> nextLargerNodes(ListNode* head) {
    vector<int> result;
    ListNode* p = head;
    while (p) {
        result.push_back(findNext(p));
        p = p->next;
    }
    return result;
}

int main()
{
    int array[] = {7,5,1,9,2,5,1};
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for (int i : array) {
        p->next = new ListNode(i);
        p = p->next;
    }
    for (int i : nextLargerNodes(head)) {
        cout << i << endl;
    }
    return 0;
}