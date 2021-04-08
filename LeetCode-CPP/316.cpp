#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <set>
using namespace std;

string removeDuplicateLetters(string s) {
    int pos[27] = {0};
    for (int i = 0; i < s.size(); i++) {
        ++pos[s[i] - 'a'];
    }
    stack<char> st;
    set<char> contain;
    for (int i = 0; i < s.size(); i++) {
        while (!st.empty() && s[i] < st.top() && 
        pos[st.top() - 'a'] > 0 && contain.find(s[i]) == contain.end()) {
            contain.erase(st.top());
            st.pop();
        }
        if (contain.find(s[i]) == contain.end()) {
            st.push(s[i]);
            contain.insert(s[i]);
        }
        --pos[s[i] - 'a'];
    }
    string result;
    while (!st.empty()) {
        result.insert(result.begin(), st.top());
        st.pop();
    }
    return result;
}

int main()
{
    string input;
    cin >> input;
    cout << removeDuplicateLetters(input) << endl;
    return 0;
}