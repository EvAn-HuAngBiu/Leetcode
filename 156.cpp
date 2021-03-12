#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

class MinStack {
private:
    vector<int> stack;
    map<int, int> m;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
        ++m[x];
    }
    
    void pop() {
        int top = this->top();
        stack.pop_back();
        --m[top];
        if (!m[top]) {
            m.erase(top);
        }
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return m.begin()->first;
    }
};

int main()
{
    return 0;
}