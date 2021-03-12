#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string reverseParentheses(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') {
            string temp;
            while (st.top() != '(') {
                temp += st.top();
                st.pop();
            }
            st.pop();
            for (int j = 0; j < temp.size(); j++) {
                st.push(temp[j]);
            }
        } else {
            st.push(s[i]);
        }
    }
    string result;
    while (!st.empty() && st.top() != '(') {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string s;
    cin >> s;
    cout << reverseParentheses(s) << endl;
    return 0;
}