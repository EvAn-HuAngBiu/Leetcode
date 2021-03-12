#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> copy(nums.begin() + size - k, nums.end());
        for (int i = size - k - 1; i >= 0; --i) {
            nums[i + k] = nums[i];
        }
        for (int i = 0; i < k; ++i) {
            nums[i] = copy[i];
        }
    }
};

int main()
{
    vector<int> v = {-1};
    Solution().rotate(v, 2);
    for (auto& i : v) {
        cout << i << endl;
    }
    return 0;
}