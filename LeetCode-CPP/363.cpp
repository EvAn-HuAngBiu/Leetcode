#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    inline int max(int a, int b) {
        return a > b ? a : b;
    }

    int subMax(const vector<int>& arr, int k) {
        int m = INT_MIN, sum;
        for (int i = 0; i < arr.size(); ++i) {
            sum = 0;
            for (int j = i; j < arr.size(); ++j) {
                sum += arr[j];
                if (sum <= k && sum > m) {
                    m = sum;
                }
            }
        }
        return m;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rlen = matrix.size(), clen = matrix[0].size();
        int m = INT_MIN;
        for (int i = 0; i < clen; ++i) {
            vector<int> curSum(rlen, 0);
            for (int j = i; j < clen; ++j) {
                for (int k = 0; k < rlen; ++k) {
                    curSum[k] += matrix[k][j];
                }
                m = max(m, subMax(curSum, k));
            }
        }
        return m;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    int k;
    cin >> k;
    cout << Solution().maxSumSubmatrix(matrix, k) << endl;
    return 0;
}