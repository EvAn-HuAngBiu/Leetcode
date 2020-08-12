#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cctype>
using namespace std;

class Solution {
private:
    set<char> rows[9];
    set<char> columns[9];
    set<char> blocks[9];
    bool visit[9][9];
    bool flag = false;
public:
    bool isnumber(char c) {
        return c >= '0' && c <= '9';
    }

    void dfs(vector<vector<char>>& board, int row, int col) {
        if (flag || (row == 9)) {
            flag = true;
            return;
        }
        if (visit[row][col]) {
            if (col == 8) {
                dfs(board, row + 1, 0);
            } else {
                dfs(board, row, col + 1);
            }
        }
        for (int i = 1; i <= 9; ++i) {
            char cur = i + '0';
            int bCnt = (row / 3) * 3 + col / 3;
            if (!visit[row][col] && rows[row].find(cur) == rows[row].end() &&
                columns[col].find(cur) == columns[col].end() &&
                blocks[bCnt].find(cur) == blocks[bCnt].end()) {
                board[row][col] = cur;
                rows[row].insert(cur);
                columns[col].insert(cur);
                blocks[bCnt].insert(cur);
                visit[row][col] = true;
                if (col == 8) {
                    dfs(board, row + 1, 0);
                } else {
                    dfs(board, row, col + 1);
                }
                if (flag) {
                    return;
                }
                visit[row][col] = false;
                rows[row].erase(cur);
                columns[col].erase(cur);
                blocks[bCnt].erase(cur);
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j) {
                if (isnumber(board[i][j])) {
                    rows[i].insert(board[i][j]);
                    columns[j].insert(board[i][j]);
                    blocks[(i / 3) * 3 + j / 3].insert(board[i][j]);
                    visit[i][j] = true;
                }
            }
        }
        dfs(board, 0, 0);
    }
};

int main()
{
    vector<vector<char>> board = {
            {'5', '3', ' ', ' ', '7', ' ', ' ', ' ', ' '},
            {'6', ' ', ' ', '1', '9', '5', ' ', ' ', ' '},
            {' ', '9', '8', ' ', ' ', ' ', ' ', '6', ' '},
            {'8', ' ', ' ', ' ', '6', ' ', ' ', ' ', '3'},
            {'4', ' ', ' ', '8', ' ', '3', ' ', ' ', '1'},
            {'7', ' ', ' ', ' ', '2', ' ', ' ', ' ', '6'},
            {' ', '6', ' ', ' ', ' ', ' ', '2', '8', ' '},
            {' ', ' ', ' ', '4', '1', '9', ' ', ' ', '5'},
            {' ', ' ', ' ', ' ', '8', ' ', ' ', '7', '9'}
    };
    Solution().solveSudoku(board);
    for (auto& b : board) {
        for (auto& c : b) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}