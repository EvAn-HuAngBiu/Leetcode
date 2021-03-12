#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (!m) {
            return 0;
        }
        int n = matrix[0].size();
        if (!n) {
            return 0;
        }
        // dp[i][j]表示以坐标(i, j)为右下角的正方形的最大边长
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int area = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        // 在第一行或第一列，只有当前位置为1时，最大面积为1（没有左上和右下了）
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    }
                    area = max(area, dp[i][j]);
                }
            }
        }
        return area * area;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    getchar();
    vector<vector<char>> matrix(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = getchar();
        }
        getchar();
    }
    cout << Solution().maximalSquare(matrix) << endl;
    return 0;
}