#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int calculate(int a, int b, char sign) {
        switch (sign) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            default: return a / b;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stringstream ss;
        vector<int> stack;
        for (auto& st : tokens) {
            ss << st;
            int cur;
            if (!(ss >> cur)) {
                int first, sec;
                sec = stack.back();
                stack.pop_back();
                first = stack.back();
                stack.pop_back();
                stack.push_back(calculate(first, sec, st[0]));
            } else {
                stack.push_back(stoi(st));
            }
            ss.clear();
        }
        return stack.back();
    }
};

int main()
{
    vector<string> s = {"2", "1", "+", "3", "*"};
    cout << Solution().evalRPN(s) << endl;
    return 0;
}