#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

inline int max(int a, int b) {
    return a > b ? a : b;
}

int sum = 0;
void dfs(const vector<int>& nums, vector<bool>& visit, int remain, int curSum) {
    int size = nums.size() - 2, s, j;
    if (remain == 0) {
        sum = max(sum, curSum);
        return;
    }
    for (int i = 1; i <= size; i++) {
        if (!visit[i]) {
            visit[i] = true;
            s = nums[i];
            j = i - 1;
            while (visit[j]) {
                j--;
            }
            s *= nums[j];
            j = i + 1;
            while (visit[j]) {
                j++;
            }
            s *= nums[j];
            dfs(nums, visit, remain - 1, curSum + s);
            visit[i] = false;
        }
    }
}

int maxCoins(vector<int>& nums) {
    int size = nums.size();
    vector<bool> visit(size + 2, false);
    nums.emplace(nums.begin(), 1);
    nums.emplace_back(1);
    for (int i = 1; i <= size; i++) {
        if (!visit[i]) {
            visit[i] = true;
            dfs(nums, visit, size - 1, nums[i - 1] * nums[i] * nums[i + 1]);
            visit[i] = false;
        }
    }
    return sum;
}

int maxCoins2(vector<int>& nums) {
    int size = nums.size();
    nums.emplace(nums.begin(), 1);
    nums.emplace_back(1);
    vector<vector<int>> dp(size + 2, vector<int>(size + 2, 0));
    for (int j = 2; j <= size + 1; j++) {
        for (int i = j - 2; i >= 0; i--) {
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = max(dp[i][j], nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]);
            }
        }
    }
    return dp[0][size + 1];
}

int main()
{
    vector<int> nums = {35,16,83,87,84,59,48,41,20,54};
    cout << maxCoins2(nums) << endl;
    return 0;
}