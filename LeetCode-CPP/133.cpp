#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<int, Node*> m;
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        if (m.find(node->val) != m.end()){
            return m[node->val];
        }
        Node* clone = new Node(node->val);
        m[node->val] = clone;
        for (Node* p : node->neighbors) {
            clone->neighbors.emplace_back(cloneGraph(p));
        }
        return clone;
    }
};

int main()
{
    return 0;
}