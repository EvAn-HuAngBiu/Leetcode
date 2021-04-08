#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pos;
    int total = 0;

    bool check(int row) {
        for (int i = 0; i < row; ++i) {
            if (pos[i] == pos[row] || abs(row - i) == abs(pos[row] - pos[i])) {
                return false;
            }
        }
        return true;
    }

    void dfs(int row, int n) {
        if (row == n) {
            ++total;
            return;
        }
        for (int i = 0; i < n; ++i) {
            pos[row] = i;
            if (check(row)) {
                dfs(row + 1, n);
            }
        }
    }

    int totalNQueens(int n) {
        pos.assign(n, 0);
        dfs(0, n);
        return total;
    }
};

int main()
{
    return 0;
}