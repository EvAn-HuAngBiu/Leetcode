#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // TLE
    int cnt = 0;
    void dfs(int cur, const int n) {
        if (cur == n) {
            cnt++;
            return;
        } else if (cur > n) {
            return;
        }
        dfs(cur + 1, n);
        dfs(cur + 2, n);
    }

    int climbStairs1(int n) {
        dfs(0, n);
        return cnt;
    }

    // 空间复杂度O(N)可以简化，观察到dp数组每次只用到了当前位的下一位和再下一位
    int climbStairs2(int n) {
        if (n == 0) {
            return 0;
        }
        vector<long long> dp(n + 1, 0);
        dp[n] = 1;
        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = dp[i + 1] + dp[i + 2];
        }
        return dp[0];
    }

    int climbStairs(int n) {
        if (n == 0) {
            return 0;
        }
        int pre1 = 1, pre2 = 1, cur;
        for (int i = n - 2; i >= 0; --i) {
            cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return pre1;
    }
};

int main()
{
    cout << Solution().climbStairs(3) << endl;
    return 0;
}