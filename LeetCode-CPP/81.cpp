#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int beg = 0, end = nums.size() - 1, mid;
        while (beg <= end) {
            mid = (beg + end) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[beg] == nums[mid]) {
                ++beg;
            } else if (nums[beg] < nums[mid]) {
                if (target < nums[mid] && target >= nums[beg]) {
                    end = mid - 1;
                } else {
                    beg = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[end]) {
                    beg = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int target;
    cin >> target;
    cout << boolalpha << Solution().search(v, target) << endl;
    return 0;
}