#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() >> 1];
    }
};

int main()
{
    vector<int> v = {3, 2, 3};
    cout << Solution().majorityElement(v) << endl;
    return 0;
}