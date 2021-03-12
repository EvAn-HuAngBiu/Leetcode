#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool flag = false;
int x_step[4] = {1, -1, 0, 0};
int y_step[4] = {0, 0, 1, -1};
vector<vector<bool>> status;
void dfs(const vector<vector<char>>& board, const string& word, int x, int y, int index) {
    if (index == word.size()) {
        flag = true;
        return;
    }
    if (flag) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + x_step[i], ny = y + y_step[i];
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()
            && board[nx][ny] == word[index] && status[nx][ny] == false) {
            status[nx][ny] = true;
            dfs(board, word, nx, ny, index + 1);
            status[nx][ny] = false;
        }
    }
}

bool exist(vector<vector<char>>& board, string word) {
    int rlen = board.size(), clen = board[0].size();
    status = vector<vector<bool>>(rlen, vector<bool>(clen, false));
    for (int i = 0; i < rlen; i++) {
        for (int j = 0; j < clen; j++) {
            if (board[i][j] == word[0]) {
                status[i][j] = true;
                dfs(board, word, i, j, 1);
                status[i][j] = false;
            }
            if (flag) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {
            {'a','a'},
    };
    string s;
    cin >> s;
    cout << exist(board, s) << endl;
    return 0;
}