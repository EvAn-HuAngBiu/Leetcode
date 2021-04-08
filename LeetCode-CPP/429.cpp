#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> result;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> cur(size);
            Node* p;
            for (int i = 0; i < size; ++i) {
                p = q.front();
                q.pop();
                cur[i] = p->val;
                for (auto& c : p->children) {
                    q.push(c);
                }
            }
            result.emplace_back(cur);
        }
        return result;
        
    }
};

int main()
{
    return 0;
}