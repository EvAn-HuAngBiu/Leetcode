#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

inline int max(int a, int b)
{
    return a > b ? a : b;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int rlen = matrix.size();
    if (rlen == 0) {
        return 0;
    }
    int clen = matrix[0].size();
    vector<vector<int>> v(rlen, vector<int>(clen, 0));
    for (int i = 0; i < rlen; ++i)
    {
        for (int j = clen - 1; j >= 0; --j)
        {
            if (matrix[i][j] == '1')
            {
                if (j == clen - 1) {
                    v[i][j] = 1;
                } else {
                    v[i][j] = v[i][j + 1] + 1;
                }
            }
        }
    }
    int maxArea = 0;
    for (int i = 0; i < rlen; i++)
    {
        for (int j = 0; j < clen; j++)
        {
            if (v[i][j] == 0)
            {
                continue;
            }
            else
            {
                int rowCnt = 0, curMin = v[i][j];
                for (int k = i; k < rlen; k++)
                {
                    if (v[k][j] == 0) {
                        break;
                    }
                    ++rowCnt;
                    curMin = min(curMin, v[k][j]);
                    maxArea = max(maxArea, rowCnt * curMin);
                }
            }
        }
    }
    return maxArea;
}

int main()
{
    vector<vector<char>> v = {{'1','0','1','1','1'},{'0','1','0','1','0'},{'1','1','0','1','1'},{'1','1','0','1','1'},{'0','1','1','1','1'}};
    cout << maximalRectangle(v) << endl;
    return 0;
}