#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = INT_MIN, size = nums.size();
        if (!size || size == 1) {
            return true;
        }
        far = nums[0];
        for (int i = 1; i < size - 1; ++i) {
            if (i <= far) {
                far = max(far, i + nums[i]);
                if (far >= size - 1) {
                    return true;
                }
            }
        }
        return far >= size - 1;
    }
};

int main()
{
    vector<int> v = {3, 2, 1, 0, 4};
    cout << boolalpha << Solution().canJump(v) << endl;
    return 0;
}