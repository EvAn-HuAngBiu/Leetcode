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
        int sum = nums[0], m = nums[0];
        for (int i = 1; i < size; ++i) {
            if (sum <= 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            m = max(m, sum);
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