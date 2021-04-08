#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    inline int max(int a, int b) {
        return a > b ? a : b;
    }

    int longestValidParentheses(string s) {
        int size = s.size();
        if (!size) {
            return 0;
        }
        stack<int> st;
        st.push(-1);
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    count = max(count, i - st.top());
                }
            }
        }
        return count;
    }
};

int main()
{
    cout << Solution().longestValidParentheses("()(()") << endl;
    return 0;
}