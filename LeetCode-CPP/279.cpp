#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX), v;
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            if (pow(int(sqrt(i)), 2) == i) {
                dp[i] = 1;
                v.emplace_back(i);
            } else {
                for (auto& last : v) {
                    dp[i] = min(dp[i], dp[i - last] + 1);
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    cout << Solution().numSquares(12) << endl;
    return 0;
}