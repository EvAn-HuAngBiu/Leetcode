#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row;
        vector<int> column;
        int r, c;
        for (int i = 0; i < 9; ++i) {
            row.assign(10, 0);
            column.assign(10, 0);
            for (int j = 0; j < 9; ++j) {
                r = board[i][j] - '0';
                c = board[j][i] - '0';
                if (r >= 0) {
                    ++row[r];
                    if (row[r] > 1) {
                        return false;
                    }
                }
                if (c >= 0) {
                    ++column[c];
                    if (column[c] > 1) {
                        return false;
                    }
                }
            }
        }

        for (int i = 0; i <= 6; i += 3) {
            for (int j = 0; j <= 6; j += 3) {
                row.assign(10, 0);
                for (int k = i; k < i + 3; ++k) {
                    for (int l = j; l < j + 3; ++l) {
                        if (board[k][l] != '.') {
                            r = board[k][l] - '0';
                            ++row[r];
                            if (row[r] > 1) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> v = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    cout << boolalpha << Solution().isValidSudoku(v) << endl;
    return 0;
}