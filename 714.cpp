#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (!n) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }

    // 常数空间复杂度的优化
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (!n) {
            return 0;
        }
        int pre_0 = 0, pre_1 = -prices[0];
        for (int i = 1; i < n; ++i) {
            pre_0 = max(pre_0, pre_1 + prices[i] - fee);
            pre_1 = max(pre_1, pre_0 - prices[i]);
        }
        return pre_0;
    }
};

int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    cout << Solution().maxProfit(prices, 2) << endl;
    return 0;
}