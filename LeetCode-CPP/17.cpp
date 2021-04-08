#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    map<int, vector<string>> m;
    vector<string> result;
    void dfs(string cur, const string& digits, int index) {
        if (index == digits.size()) {
            result.emplace_back(cur);
            return;
        }
        const vector<string>& letters = m[digits[index] - '0'];
        for (const string& s : letters) {
            dfs(cur + s, digits, index + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        m[2] = {"a", "b", "c"};
        m[3] = {"d", "e", "f"};
        m[4] = {"g", "h", "i"};
        m[5] = {"j", "l", "l"};
        m[6] = {"m", "n", "o"};
        m[7] = {"p", "q", "r", "s"};
        m[8] = {"t", "u", "v"};
        m[9] = {"w", "x", "y", "z"};
        const vector<string>& letters = m[digits[0] - '0'];
        for (string s : letters) {
            dfs(s, digits, 1);
        }
        return result;
    }
};

int main()
{
    for (const string& s : Solution().letterCombinations("234")) {
        cout << s << endl;
    }
    return 0;
}