#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size(), ava = 1, p = 1;
        if (size == 0) {
            return 0;
        }
        int pre = nums[0];
        while (p < size) {
            if (nums[p] == pre) {
                ++p;
            } else {
                pre = nums[p];
                nums[ava++] = nums[p++];
            }
        }
        return ava;
    }
};

int main()
{
    return 0;
}