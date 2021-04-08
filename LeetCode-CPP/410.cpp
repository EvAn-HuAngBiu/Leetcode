#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    inline int min(int a, int b) {
        return a < b ? a : b;
    }

    inline int max(int a, int b) {
        return a > b ? a : b;
    }

    int splitArray(vector<int>& nums, int m) {
        int size = nums.size();
        vector<int> sum(size + 1, 0);
        vector<vector<int>> dp(size + 1, vector<int>(size + 1, INT_MAX));
        for (int i = 1; i <= size; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        dp[0][0] = 0;
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sum[i] - sum[k]));
                }
            }
        }
        return dp[size][m];
    }
};

int main()
{
    return 0;
}