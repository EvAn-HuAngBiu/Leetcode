#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = 0, size = nums.size();
        while (beg < size - 1) {
            if (nums[beg] > nums[beg + 1]) {
                break;
            }
        }
        int end;
        if (target < nums[beg]) {
            end = beg;
            beg = 0;
        } else if (target == nums[beg]) {
            return beg;
        } else {
            
        }
    }
};

int main()
{
    return 0;
}