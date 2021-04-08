#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    inline int cmp(int a, int b, bool type) {
        if (type) {
            return (a > b ? a : b);
        }
        return (a < b ? a : b);
    }

    int left = INT_MAX, right = INT_MIN;
    void loop(const vector<int>& nums, int beg, int end, int target) {
        if (beg < 0 || end >= nums.size()) {
            return;
        }
        int mid;
        while (beg <= end) {
            mid = (beg + end) / 2;
            if (nums[mid] == target) {
                left = cmp(left, mid, false);
                right = cmp(right, mid, true);
                loop(nums, beg, mid - 1, target);
                loop(nums, mid + 1, end, target);
                return;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        loop(nums, 0, nums.size() - 1, target);
        return {left == INT_MAX ? -1 : left, right == INT_MIN ? -1 : right};
    }
};

int main()
{
    vector<int> v = {5, 7, 7, 8, 8, 8, 8, 9, 10, 10};
    vector<int> result = Solution().searchRange(v, 8);
    cout << result[0] << ", " << result[1] << endl;
    return 0;
}