#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rlen = matrix.size(), clen = matrix[0].size();
        if (!rlen) {
            return;
        }
        for (int i = 0; i < rlen; ++i) {
            for (int j = i + 1; j < clen; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
    };
    Solution().rotate(matrix);
    for (const vector<int>& v : matrix) {
        for (auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}