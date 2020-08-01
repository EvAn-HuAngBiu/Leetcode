#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size == 0 || size == 1) {
            return;
        } else if (size == 2) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int p = size - 1, q = p - 1;
        while (q >= 0 && nums[q] >= nums[p]) {
            --q;
        }
        if (q < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        int temp = nums[p];
        nums[p] = nums[q];
        nums[q] = temp;
        sort(nums.begin() + q + 1, nums.end() + p);
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4};
    Solution().nextPermutation(v);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}