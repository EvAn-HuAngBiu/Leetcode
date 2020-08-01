#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = 0, end = nums.size() - 1, mid;
        while (beg <= end) {
            mid = (beg + end) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > nums[beg]) {
                if (target >= nums[beg] && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    beg = mid + 1;
                }
            } else {
                if (target >= nums[mid] && target <= nums[end]) {
                    beg = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> v = {4,5,6,7,0,1,2};
    cout << Solution().search(v, 0) << endl;
    return 0;
}