#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (!m) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        if (obstacleGrid[m - 1][n - 1] == 0) {
            dp[m - 1][n - 1] = 1;
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1) {
                    continue;
                }
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else if (i == m - 1) {
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
    return 0;
}