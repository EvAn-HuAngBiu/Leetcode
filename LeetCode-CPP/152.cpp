#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxVal = INT_MIN;
        int imin = 1, imax = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                int temp = imin;
                imin = imax;
                imax = temp;
            }
            imin = min(nums[i], imin * nums[i]);
            imax = max(nums[i], imax * nums[i]);
            maxVal = max(maxVal, imax);
        }
        return maxVal;
    }
};

int main()
{
    vector<int> v = {2, 3, -2, 4, -2};
    cout << Solution().maxProduct(v) << endl;
    return 0;
}