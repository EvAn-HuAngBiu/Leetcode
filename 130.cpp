#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int m, n;
public:
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x >= m || x < 0 || y >= n || y < 0 || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (!m) {
            return;
        }
        n = board[0].size();
        for (int i = 0; i < n; ++i) {
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }
        for (int i = 0; i < m; ++i) {
            dfs(board, i, n - 1);
            dfs(board, i, 0);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = (board[i][j] == 'O' ? 'X' : (board[i][j] == 'A' ? 'O' : 'X'));
            }
        }
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> v(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    Solution().solve(v);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v[i][j];
        }
        cout << endl;
    }
    return 0;
}