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

    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        vector<int> dp(size + 1, 0);
        dp[0] = nums[0];
        int m = nums[0];
        for (int i = 1; i < size; i++) {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
            m = max(m, dp[i]);
        }
        return m;
    }
};

int main()
{
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().maxSubArray(v) << endl;
    return 0;
}