#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int step[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int oldColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push(pair<int, int>(sr, sc));
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            image[cur.first][cur.second] = newColor;
            for (int i = 0; i < 4; ++i) {
                int nx = cur.first + step[i][0], ny = cur.second + step[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == oldColor && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push(pair<int, int>(nx, ny));
                }
            }
        }
        return image;
    }
};

int main()
{
    vector<vector<int>> image = {
        {1, 1, 1}, {1, 1, 0}, {1, 0, 1}
    };
    auto result = Solution().floodFill(image, 1, 1, 2);
    for (auto& v : result) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}