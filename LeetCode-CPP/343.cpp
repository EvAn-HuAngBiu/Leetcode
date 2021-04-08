#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    inline int max(int a, int b) {
        return a > b ? a : b;
    }

    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(j * (i - j), dp[i - j] * j));
            }
        }
        return dp[n];
    }
};

int main()
{
    cout << Solution().integerBreak(10) << endl;
    return 0;
}