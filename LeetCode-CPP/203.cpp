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
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 添加空头结点
        ListNode* root = new ListNode(-1);
        root->next = head;

        ListNode* p = root, *q = head;
        while (q) {
            if (q->val == val) {
                p->next = q->next;
                q = q->next;
            } else {
                p = p->next;
                q = q->next;
            }
        }
        return root->next;
    }
};

int main()
{
    ListNode* head = new ListNode(6, new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(6)))))));
    ListNode* c = Solution().removeElements(head, 6);
    ListNode* p = c;
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}