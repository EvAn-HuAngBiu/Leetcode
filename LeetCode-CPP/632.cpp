#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    struct Val {
        int value;
        int row;
        int column;

        Val() {}
        Val(int value, int row, int column) : value(value), row(row), column(column) {}
    };

    struct great {
        bool operator()(const Val& v1, const Val& v2) {
            return v1.value < v2.value;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Val, vector<Val>, great> small;
        priority_queue<int> big;
        for (int i = 0; i < nums.size(); ++i) {
            small.push(Val(nums[i][0], i, 0));
        }
        int left = 0, right = INT_MAX;
        Val sm;
        int bg;
        while (1) {
            sm = small.top();
            small.pop();
            bg = big.top();
            if (bg - sm.value < right - left) {
                left = sm.value;
                right = bg;
            }
            if (sm.column + 1 == nums[sm.row].size()) {
                break;
            }
            small.push(Val(nums[sm.row][sm.column + 1], sm.row, sm.column + 1));
            big.push(nums[sm.row][sm.column + 1]);
        }
        return {left, right};
    }
};

int main()
{
    vector<vector<int>> v = {
        {4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}
    };
    vector<int> result = Solution().smallestRange(v);
    cout << result[0] << " ," << result[1] << endl;
    return 0;
}