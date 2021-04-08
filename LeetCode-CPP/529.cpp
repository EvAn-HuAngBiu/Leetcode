#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    int step[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int m, n;
public:
    int countMines(const vector<vector<char>>& board, int x, int y) {
        int count = 0;
        for (int i = 0; i < 8; ++i) {
            int nx = x + step[i][0], ny = y + step[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'M') {
                ++count;
            }
        }
        return count;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        pair<int, int> cur(click[0], click[1]);
        board[click[0]][click[1]] = 'B';
        queue<pair<int, int>> q;
        q.push(cur);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            int cnt = countMines(board, cur.first, cur.second);
            if (cnt > 0) {
                board[cur.first][cur.second] = cnt + '0';
            } else {
                for (int i = 0; i < 8; ++i) {
                    int nx = cur.first + step[i][0], ny = cur.second + step[i][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'E') {
                        board[nx][ny] = 'B';
                        q.push(pair<int, int>(nx, ny));
                    }
                }
            }
        }
        return board;
    }
};

int main()
{
    vector<vector<char> > board;
    int m,n,x,y;
    cin>>m;
    cin>>n;

    char ch;
    for(int i=0; i<m; i++)
    {
        vector<char> aLine;
        for(int j=0; j<n; j++)
        {
            cin>>ch;
            aLine.push_back(ch);
        }
        board.push_back(aLine);
    }
    cin>>x>>y;
    vector<int> click;
    click.push_back(x);
    click.push_back(y);
    vector<vector<char>> res=Solution().updateBoard(board,click);
    for(int i=0; i<res.size(); i++)
    {
        vector<char> aLine = res[i];
        for(int j=0; j<aLine.size(); j++)
            cout<<aLine[j];
        cout<<endl;
    }
    return 0;
}