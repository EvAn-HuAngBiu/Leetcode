#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        if (size < 4) {
            return {};
        }
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int p, q;
        for (int i = 0; i < size; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < size; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                p = j + 1;
                q = size - 1;
                while (p < q) {
                    int sum = nums[i] + nums[j] + nums[p] + nums[q];
                    if (sum == target) {
                        result.emplace_back(vector<int>{nums[i], nums[j], nums[p], nums[q]});
                        while (p < q && nums[p] == nums[p + 1]) {
                            ++p;
                        }
                        while (p < q && nums[q] == nums[q - 1]) {
                            --q;
                        }
                        ++p;
                        --q;
                    } else if (sum > target) {
                        --q;
                    } else {
                        ++p;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> v = {1,-2,-5,-4,-3,3,3,5};
    vector<vector<int>> result = Solution().fourSum(v, -11);
    for (auto& r : result) {
        for (auto& i : r) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}