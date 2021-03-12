#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int beg = 0, end = nums.size() - 1, mid;
    if (end == 0) {
        return nums[0];
    }
    while (beg <= end) {
        mid = (beg + end) / 2;
        if (nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }
        if (nums[mid] > nums[end]) {
            beg = mid + 1;
        } else if (nums[mid] < nums[end]) {
            end = mid;
        } else {
            return nums[mid];
        }
    }
    return nums[beg];
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << findMin(v) << endl;
    return 0;
}