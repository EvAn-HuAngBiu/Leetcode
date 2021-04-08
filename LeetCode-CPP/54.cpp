#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int row;
    int column;
    int rCnt;
    int cCnt;

    vector<int> handleLoop(const vector<vector<int>>& m, int x, int y) {
        vector<int> result;
        for (int i = 0; i < cCnt; ++i) {
            result.emplace_back(m[x][i + y]);
        }
        for (int i = 1; i < rCnt; ++i) {
            result.emplace_back(m[x + i][y + cCnt - 1]);
        }
        for (int i = cCnt - 2; rCnt > 1 && i > 0; --i) {
            result.emplace_back(m[x + rCnt - 1][i + y]);
        }
        for (int i = rCnt - 1; cCnt > 1 && i > 0; --i) {
            result.emplace_back(m[i + x][y]);
        }
        return result;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        row = matrix.size();
        if (row == 0) {
            return {};
        }
        column = matrix[0].size();
        if (column == 0) {
            return {};
        }
        rCnt = row;
        cCnt = column;
        int i = 0, total = row * column;
        while (result.size() != total) {
            vector<int> v = handleLoop(matrix, i, i);
            result.insert(result.end(), v.begin(), v.end());
            rCnt -= 2;
            cCnt -= 2;
            ++i;
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> m = {
            {3}, {2}
    };
    vector<int> result = Solution().spiralOrder(m);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}