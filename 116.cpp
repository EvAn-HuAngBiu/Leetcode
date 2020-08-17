#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
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
public:
    Node* connect(Node* root) {
        if (!root || (!root->left && !root->right)) {
            return root;
        }
        int size;
        queue<vector<Node*>> q;
        vector<Node*> cur;
        cur.emplace_back(root);
        q.push(cur);
        while (!q.empty()) {
            vector<Node*> last = q.front();
            q.pop();
            vector<Node*> next;
            size = last.size();
            last.emplace_back(nullptr);
            for (int i = 0; i < size; ++i) {
                last[i]->next = last[i + 1];
                if (last[i]->left) {
                    next.emplace_back(last[i]->left);
                }
                if (last[i]->right) {
                    next.emplace_back(last[i]->right);
                }
            }
            if (!next.empty()) {
                q.push(next);
            }
        }
        return root;
    }
};

int main()
{
    Node* root = new Node(1, new Node(2, new Node(4), new Node(5)), new Node(3, new Node(6), new Node(7)));
    // Node* root = new Node(1, new Node(2, new Node(4, new Node(7)), new Node(5)), new Node(3, NULL, new Node(6, NULL, new Node(8))));

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