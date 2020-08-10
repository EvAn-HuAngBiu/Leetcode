#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int m, n;
    int cnt;
    int x_step[2] = {0, 1};
    int y_step[2] = {1, 0};
public:

    // TLE
    void dfs(int x, int y) {
        if (x + 1 == m && y + 1 == n) {
            ++cnt;
            return;
        }
        for (int i = 0; i < 2; ++i) {
            int nx = x_step[i] + x, ny = y_step[i] + y;
            if (nx < m && ny < n) {
                dfs(nx, ny);
            }
        }
    }

    int uniquePaths1(int m, int n) {
        this->m = m;
        this->n = n;
        this->cnt = 0;
        dfs(0, 0);
        return cnt;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1) {
                    continue;
                }
                if (i == m - 1) {
                    dp[i][j] = dp[i][j + 1];
                } else if (j == n - 1) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i][j + 1] +  dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};

int main()
{
    cout << Solution().uniquePaths(7, 3) << endl;
    return 0;
}