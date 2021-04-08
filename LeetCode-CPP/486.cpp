#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int handle(vector<int>& nums, int beg, int end, int turn) {
        if (beg == end) {
            return nums[beg] * turn;
        }
        int front = nums[beg] * turn + handle(nums, beg + 1, end, -turn);
        int back = nums[end] * turn + handle(nums, beg, end - 1, -turn);
        return max(front * turn, back * turn) * turn;
    }

    bool PredictTheWinner1(vector<int>& nums) {
        return handle(nums, 0, nums.size() - 1, 1) >= 0;
    }

    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size);
        for (int i = 0; i < size; ++i) {
            dp[i]= nums[i];
        }
        for (int i = size - 2; i >= 0; --i) {
            for (int j = i + 1; j < size; ++j) {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        return dp[size - 1] >= 0;
    }
};

int main()
{
    vector<int> v = {1, 5, 2};
    cout << boolalpha << Solution().PredictTheWinner(v) << endl;
    return 0;
}