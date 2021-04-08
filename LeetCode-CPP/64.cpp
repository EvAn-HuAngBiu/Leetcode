#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int step[2][2] = {{1, 0}, {0, 1}};
int result = 0x7fffffff;

inline int min(int a, int b) {
    return a < b ? a : b;
}

// TLE
void dfs(const vector<vector<int>>& g, int x, int y, int sum) {
    if (x == g.size() - 1 && y == g[0].size() - 1) {
        result = min(result, sum);
        return;
    }
    for (int i = 0; i < 2; i++) {
        int nx = x + step[i][0], ny = y + step[i][1];
        if (nx >= 0 && nx < g.size() && ny >= 0 && ny < g[0].size()) {
            dfs(g, nx, ny, sum + g[nx][ny]);
        }
    }
}

int dp(const vector<vector<int>>& grid) {
    int rlen = grid.size(), clen = grid[0].size();
    vector<vector<int>> dp(rlen, vector<int>(clen, 0));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < rlen; i++) {
        for (int j = 0; j < clen; j++) {
            if (!i && !j) {
                continue;
            }
            if (i == 0) {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            } else {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
    }
    return dp[rlen - 1][clen - 1];
}

int minPathSum(vector<vector<int>>& grid) {
    // dfs(grid, 0, 0, grid[0][0]);
    return dp(grid);
}

int main()
{
    return 0;
}