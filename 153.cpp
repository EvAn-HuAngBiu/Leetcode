#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] > nums[i]) {
            return nums[i];
        }
    }
    return nums[0];
}

int main()
{
    vector<int> v = {1,2};
    cout << findMin(v) << endl;
    return 0;
}