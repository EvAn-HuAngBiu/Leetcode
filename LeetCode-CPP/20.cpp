#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char i : s) {
        if (i == '[' || i == '{' || i == '(') {
            st.push(i);
            continue;
        } else if (st.empty() || (i == ']' && st.top() != '[') || (i == '}' && st.top() != '{')
                    || (i == ')' && st.top() != '(')) {
            return false;
        }
        st.pop();
    }
    return st.empty();
}

int main()
{
    return 0;
}