#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.emplace_back(1);
        nums.emplace(nums.begin(), 1);
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(size));
        for (int j = 2; j < size; ++j) {
            for (int i = j - 2; i >= 0; --i) {
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], nums[i] * nums[j] * nums[k] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][size - 1];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << Solution().maxCoins(v) << endl;
    return 0;
}