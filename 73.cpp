#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int m, n;
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool column = false;
        m = matrix.size();
        if (!m) {
            return;
        }
        n = matrix[0].size();
        if (!n) {
            return;
        }
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                column = true;
            }
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0)  {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (!matrix[0][0]) {
            for (int i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }
        if (column) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    vector<vector<int>> v = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };
    Solution().setZeroes(v);
    for (auto& p : v) {
        for (auto& i : p) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}