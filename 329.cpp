#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> dp;
int xStep[] = {0, 0, 1, -1};
int yStep[] = {1, -1, 0, 0};
inline int max(int a, int b) {
    return a > b ? a : b;
}

int dfs(const vector<vector<int>>& matrix, int x, int y) {
    if (dp[x][y] != 0) {
        return dp[x][y];
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + xStep[i], ny = y + yStep[i];
        if (nx >= 0 && nx < matrix.size() && ny >= 0 && ny < matrix[0].size() 
                && matrix[nx][ny] > matrix[x][y]) {
            dp[x][y] = max(dp[x][y], dfs(matrix, nx, ny));
        }
    }
    return ++dp[x][y];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) {
        return 0;
    }
    int rlen = matrix.size(), clen = matrix[0].size();
    dp.assign(rlen, vector<int>(clen, 0));
    int result = 0;
    for (int i = 0; i < rlen; i++) {
        for (int j = 0; j < clen; j++) {
            result = max(result, dfs(matrix, i, j));
        }
    }
    return result;
}

int main()
{
    return 0;
}