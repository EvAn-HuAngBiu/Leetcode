#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> se(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && se.find(s.substr(j, i - j)) != se.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main()
{
    string s;
    cin >> s;
    int cnt;
    cin >> cnt;
    vector<string> words(cnt);
    for (int i = 0; i < cnt; ++i) {
        cin >> words[i];
    }
    cout << boolalpha << Solution().wordBreak(s, words) << endl;
    return 0;
}