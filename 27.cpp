#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size(), ava = 0, p = 0;
        if (size == 0) {
            return 0;
        }
        while (p < size) {
            if (nums[p] == val) {
                ++p;
            } else {
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