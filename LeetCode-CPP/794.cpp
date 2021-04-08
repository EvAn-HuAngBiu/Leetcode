#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool canWin(const vector<string>& board, char c) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == c) {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == c) {
            return true;
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == c) ||
            board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == c) {
        return true;
    }
    return false;
}

bool validTicTacToe(vector<string>& board) {
    int o = 0, x = 0;
    for (const string& s : board) {
        for (const char& c : s) {
            if (c == 'O') {
                ++o;
            } else if (c == 'X') {
                ++x;
            }
        }
    }
    if (o > x || x - o > 1) {
        return false;
    } else if (canWin(board, 'X') && x != o + 1) {
        return false;
    } else if (canWin(board, 'O') && x != o) {
        return false;
    }
    return true;
}

int main()
{
    return 0;
}