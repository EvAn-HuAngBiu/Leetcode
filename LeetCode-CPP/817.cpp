#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool find(const vector<int>& array, int val) {
    int beg = 0, end = array.size() - 1;
    int mid;
    while (beg <= end) {
        mid = (beg + end) / 2;
        if (array[mid] == val) {
            return true;
        } else if (array[mid] < val) {
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}

int numComponents(ListNode* head, vector<int>& G) {
    sort(G.begin(), G.end());
    int result = 0;
    ListNode* p = head;
    bool flag = false;
    while (p) {
        if (find(G, p->val)) {
            flag = true;
        } else if (flag) {
            ++result;
            flag = false;
        }
        p = p->next;
    }
    return result + (flag ? 1 : 0);
}

int main()
{
    ListNode* head = new ListNode(0), *p = head;
    for (int i = 1; i <= 3; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    vector<int> v = {0, 1, 3};
    cout << numComponents(head, v);
    return 0;
}