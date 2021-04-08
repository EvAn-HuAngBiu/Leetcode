#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int size;
    inline int max(int a, int b) {
        return a > b ? a : b;
    }

    int* robHelper(const vector<int>& nums, int index) {
        if (index == size) {
            return new int[2]{0, 0};
        }
        int* next = robHelper(nums, index + 1);
        int* result = new int[2];
        result[0] = max(next[0], next[1]);
        result[1] = next[0] + nums[index];
        return result;
    }

    int rob1(vector<int>& nums) {
        size = nums.size();
        int* result = robHelper(nums, 0);
        return max(result[0], result[1]);
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        } else if (size == 1) {
            return nums[0];
        }
        int pre1 = nums[0], pre2 = max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i) {
            int cur = pre2;
            pre2 = max(pre1 + nums[i], pre2);
            pre1 = cur;
        }
        return pre2;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 1};
    cout << Solution().rob(v) << endl;
    return 0;
}