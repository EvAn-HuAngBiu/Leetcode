#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right = NULL) : val(_val), left(_left), right(_right), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
private:
    Node* pre = nullptr, *left = nullptr;
public:
    void connectHelper(Node*& p) {
        if (p) {
            if (pre) {
                pre->next = p;
            } else {
                left = p;
            }
            pre = p;
        }
    }

    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        left = root;
        while (left) {
            Node* p = left;
            left = nullptr;
            pre = nullptr;
            while (p) {
                connectHelper(p->left);
                connectHelper(p->right);
                p = p->next;
            }
        }
        return root;
    }
};

int main()
{
    Node* root = new Node(1, new Node(2, new Node(4, new Node(7)), new Node(5)), new Node(3, NULL, new Node(6, NULL, new Node(8))));
    root = Solution().connect(root);
    Node* p = root;
    while (p) {
        Node* q = p;
        while (q) {
            cout << q->val << " ";
            q = q->next;
        }
        cout << endl;
        p = p->left;
    }
    return 0;
}