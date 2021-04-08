#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        if (size < 3) {
            return 0;
        }
        long near = INT_MAX;
        sort(nums.begin(), nums.end());
        int p, q;
        for (int i = 0; i < size; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            p = i + 1;
            q = size - 1;
            while (p < q) {
                int sum = nums[i] + nums[p] + nums[q];
                if (sum == target) {
                    return target;
                } else {
                    near = abs(near - target) > abs(sum - target) ? sum : near;
                    if (sum > target) {
                        --q;
                    } else {
                        ++p;
                    }
                }
            }
        }
        return near;
    }
};

int main()
{
    vector<int> v = {1, 1, 1, 1};
    cout << Solution().threeSumClosest(v, -100) << endl;
    return 0;
}