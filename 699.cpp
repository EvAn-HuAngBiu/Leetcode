#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int s = positions.size();
        // 记录每个方块离地面的基准高度，当有两个方块重叠时，基准高度就提高了
        // 当一个方块落下之后，就记录了当前这一列的高度
        vector<int> base(s);
        for (int i = 0; i < s; ++i) {
            int left = positions[i][0];
            int size = positions[i][1];
            int right = left + size;
            // 在基准高度之上叠加，即加上当前高度
            base[i] += size;

            // 计算当前高度增加会对后面未放置的正方形基准高度产生的影响
            for (int j = i + 1; j < s; ++j) {
                int l2 = positions[j][0], s2 = positions[j][1], r2 = l2 + s2;
                if (l2 < right && r2 > left) {
                    base[j] = max(base[j], base[i]);
                }
            }
        }

        // 计算方块落下后的最大高度
        int pre = -1;
        for (int i = 0; i < s; ++i) {
            pre = max(pre, base[i]);
            base[i] = pre;
        }
        return base;
    }
};

class Solution2 {
    
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> v[i][0] >> v[i][1];
    }
    vector<int> result = Solution().fallingSquares(v);
    for (int i = 0; i < n; ++i) {
        if (i) {
            cout << " ";
        }
        cout << result[i];
    }
    return 0;
}