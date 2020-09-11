#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (!size) {
            return;
        }
        int i = size - 1;
        while (i > 0 && nums[i] <= nums[i - 1]) {
            --i;
        }
        if (!i) {
            // 找不到逆序对，说明是最大值，重新排序即可
            sort(nums.begin(), nums.end());
            return;
        }
        int j = i;
        while (j + 1 < size && nums[j + 1] > nums[i - 1]) {
            ++j;
        }
        int temp = nums[j];
        nums[j] = nums[i - 1];
        nums[i - 1] = temp;
        reverse(nums.begin() + i, nums.end());
    }
};

int main()
{
    vector<int> v = {5, 1, 1};
    Solution().nextPermutation(v);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}