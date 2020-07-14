#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// int route = 0;
inline int max(int a, int b) {
    return a > b ? a : b;
}

// void dfs(const vector<vector<int>>& v, int row, int col, int sum) {
//     if (row + 1 == v.size()) {
//         route = max(route, sum);
//     }
//     int s = sum + v[row][col];
//     dfs(v, row + 1, col, s);
//     dfs(v, row + 1, col + 1, s);
// }

// int minimumTotal(vector<vector<int>>& triangle) {
//     dfs(triangle, 0, 0, 0);
//     return route;
// }

int minimumTotal(vector<vector<int>>& triangle) {
    int size = triangle.size();
    vector<vector<int>> dp(size, vector<int>(size));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < size; i++) {
        int s = triangle[i].size();
        for (int j = 0; j < s; j++) {
            if (j == 0) {
                dp[i][j] = triangle[i][j] + dp[i - 1][j];
            } else if (j == s - 1) {
                dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
            } else {
                dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }
    int route = 0x7fffffff;
    for (int i = 0; i < size; i++) {
        route = min(route, dp[size - 1][i]);
    }
    return route;
}

int main()
{
    vector<vector<int>> v = {
            {2},
            {3,4},
            {6,5,7},
            {4,1,8,3}
    };
    cout << minimumTotal(v) << endl;
    return 0;
}