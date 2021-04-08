#include <iostream>
#include <stack>
#include <string>
using namespace std;

int minAddToMakeValid(string S) {
    stack<char> st;
    for (int i = 0; i < S.size(); i++) {
        if (!st.empty() && S[i] == ')' && st.top() == '(') {
            st.pop();
        } else {
            st.push(S[i]);
        }
    }
    return st.size();
}

int main()
{
    string s;
    cin >> s;
    cout << minAddToMakeValid(s) << endl;
    return 0;
}