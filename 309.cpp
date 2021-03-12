#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit1(vector<int>& prices) {
        int size = prices.size();
        if (!size) {
            return 0;
        }
        // 第一个状态表示第i天，第二个状态0表示第i天未持有股票的最大收益，1表示持有股票的最大收益
        vector<vector<int>> dp(size, vector<int>(2, 0));
        // 初始：第0天未持有股票则收益为0，否则收益为购买入第一天股票的价格（负收益）
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < size; ++i) {
            // 第i天持有未持有股票有两种情况：1.前一天未持有，今天也不持有，则收益和前一天一样
            // 2.前一天持有，今天卖掉它，则收益等于前一天持有的收益+今天买掉股票的收益
            // 取以上两个最大值就行
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 第i天持有股票也有两种情况，要么前一天持有，今天也持有那么收益和前一天一样；要么
            // 前两天未持有（考虑冷冻期一天），今天买入股票。同取最大值即可
            if (i - 2 >= 0) {
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
            } else {
                dp[i][1] = max(dp[i - 1][1], -prices[i]);
            }
        }
        return dp[size - 1][0];
    }

    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (!size) {
            return 0;
        }
        // 考虑到上面的函数每次遍历只找前一天持有、未持有和前两天未持有的收益，那么只要保存这三项即可
        int pre1_hold = -prices[0], pre1_not_hold = 0, pre2_not_hold = 0;
        for (int i = 1; i < size; ++i) {
            int cur_not_hold = max(pre1_not_hold, pre1_hold + prices[i]);
            pre1_hold = max(pre1_hold, pre2_not_hold - prices[i]);
            pre2_not_hold = pre1_not_hold;
            pre1_not_hold = cur_not_hold;
        }
        return pre1_not_hold;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}