#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int x_step[] = {1, -1, 0, 0}, y_step[] = {0, 0, 1, -1};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dis(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    visited[i][j] = true;
                    q.push(pair<int, int>(i, j));
                }
            }
        }
        while (!q.empty()) {
            pair<int, int> index = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = index.first + x_step[i], ny = index.second + y_step[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    q.push(pair<int, int>(nx, ny));
                    visited[nx][ny] = true;
                    dis[nx][ny] = dis[index.first][index.second] + 1;
                }
            }
        }
        return dis;
    }
};

int main()
{
    vector<vector<int> > matrix;
    int m,n;
    cin>>m;
    cin>>n;

    char ch;
    for(int i=0; i<m; i++)
    {
        vector<int> aLine;
        for(int j=0; j<n; j++)
        {
            cin>>ch;
            aLine.push_back(ch-'0');
        }
        matrix.push_back(aLine);
    }

    vector<vector<int>> res=Solution().updateMatrix(matrix);
    for(int i=0; i<res.size(); i++)
    {
        vector<int> aLine = res[i];
        for(int j=0; j<aLine.size(); j++)
            cout<<aLine[j];
        cout<<endl;
    }
    return 0;
}