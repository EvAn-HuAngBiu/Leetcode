#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int beg = 0, end = nums.size() - 1, mid;
    while (beg <= end) {
        mid = (beg + end) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target > nums[mid]) {
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return beg;
}

int main()
{
    vector<int> v = {};
    int n;
    while (cin >> n) {
        cout << searchInsert(v, n) << endl;
    }
    return 0;
}