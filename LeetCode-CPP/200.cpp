#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; ++i) {
            int nx = x + step[i][0];
            int ny = y + step[i][1];
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1') {
                dfs(grid, nx, ny);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};

int main()
{
    return 0;
}