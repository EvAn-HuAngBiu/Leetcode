#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int sa = s1.size(), sb = s2.size(), sc = s3.size();
    if (sa + sb != sc) {
        return false;
    }
    vector<vector<bool>> dp(sa + 1, vector<bool>(sb + 1, false));
    dp[0][0] = true;     
    for (int i = 0; i <= sa; i++) {
        for (int j = 0; j <= sb; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (i == 0) {
                dp[0][j] = (dp[0][j - 1] && s2[j - 1] == s3[j - 1]);
            } else if (j == 0) {
                dp[i][0] = (dp[i - 1][0] && s1[i - 1] == s3[i - 1]);
            } else {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || 
                            (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
    }
    return dp[sa][sb];
}

int main()
{
    cout << boolalpha << isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    return 0;
}