#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums, int n) {
        int size = nums.size();
        if (!size) {
            return;
        }
        for (int t = 1; t < n; ++t) {
            int i = size - 1;
            while (i > 0 && nums[i] <= nums[i - 1]) {
                --i;
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
    }

    string getPermutation(int n, int k) {
        vector<int> v(n);
        for (int i = 1; i <= n; ++i) {
            v[i - 1] = i;
        }
        nextPermutation(v, k);
        string result;
        for (auto& i : v) {
            result += to_string(i);
        }
        return result;
    }
};

int main()
{
    cout << Solution().getPermutation(4, 9) << endl;
    return 0;
}