#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<int> pos;

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
            vector<string> r(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                r[i][pos[i]] = 'Q';
            }
            result.emplace_back(r);
            return;
        }
        for (int i = 0; i < n; ++i) {
            pos[row] = i;
            if (check(row)) {
                dfs(row + 1, n);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        pos.assign(n, 0);
        dfs(0, n);
        return result;
    }
};

int main()
{
    vector<vector<string>> r = Solution().solveNQueens(4);
    for (const vector<string>& s) {
        for (const string& r : s) {
            cout << r << endl;
        }
        cout << endl;
    }
    return 0;
}