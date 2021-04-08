#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int cnt;
    int handleLoop(vector<vector<int>>& m, int x, int y, int n) {
        for (int i = 0; i < cnt; ++i) {
            m[x][i + y] = n++;
        }
        for (int i = 1; i < cnt; ++i) {
            m[x + i][y + cnt - 1] = n++;
        }
        for (int i = 1; i < cnt; ++i) {
            m[x + cnt - 1][y + cnt - 1 - i] = n++;
        }
        for (int i = 1; i < cnt - 1; ++i) {
            m[x + cnt - 1 - i][y] = n++;
        }
        return n;
    }

    vector<vector<int>> generateMatrix(int n) {
        if (!n) {
            return {};
        }
        cnt = n;
        int cur = 1, x = 0, y = 0;
        vector<vector<int>> m(n, vector<int>(n, 0));
        while (cnt > 0) {
            cur = handleLoop(m, x++, y++, cur);
            cnt -= 2;
        } 
        return m;
    }
};

int main()
{
    vector<vector<int>> m = Solution().generateMatrix(3);
    for (auto& v : m) {
        for (auto& p : v) {
            cout << p << " ";
        }
        cout << endl;
    }
    return 0;
}