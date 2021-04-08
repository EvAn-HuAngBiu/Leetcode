#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit1(vector<int>& prices) {
        int n = prices.size();
        int times = 2;
        if (!n) {
            return 0;
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(times + 1, vector<int>(2, 0)));
        for (int k = 0; k <= times; ++k) {
            dp[0][k][1] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int k = 1; k <= times; ++k) {
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][times][0];
    }

    int maxProfit(vector<int>& prices) {
        int pre_1_0 = 0, pre_1_1 = INT_MIN, pre_2_0 = 0, pre_2_1 = INT_MIN;
        for (auto& i : prices) {
            pre_2_0 = max(pre_2_0, pre_2_1 + i);
            pre_2_1 = max(pre_2_1, pre_1_0 - i);
            pre_1_0 = max(pre_1_0, pre_1_1 + i);
            pre_1_1 = max(pre_1_1, -i);
        }
        return pre_2_0;
    }
};

int main()
{
    vector<int> v = {3,3,5,0,0,3,1,4};
    cout << Solution().maxProfit(v) << endl;
    return 0;
}