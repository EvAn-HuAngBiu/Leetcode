#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (!(m && n)) {
            return m + n;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    // 如果两个字符串末尾字符相同，那么就不用操作，和前一步的步数相同
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 否则：1. dp[i][j - 1]表示用第一个字符串的前i个字符转换为第二个字符串的前j-1个字符，
                    // 然后再给第二个串末尾添加一个字符（即步骤数+1）
                    // 2. dp[i - 1][j]表示用第一个字符串的前i-1个字符转换为第二个字符串的前j个字符，
                    // 然后再给第一个串末尾添加一个字符
                    // 3. dp[i - 1][j - 1]表示用第一个字符串的前i-1个字符转换为第二个字符串的前j-1个字符，
                    // 然后再把各自的最后一个字符替换成一致的即可（即步骤数+1）
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << Solution().minDistance(s1, s2) << endl;
    return 0;
}