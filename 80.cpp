#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 2) {
            return size;
        }
        int available = 2, cur = 2;
        while (cur < size) {
            if (nums[cur] == nums[available - 1] && nums[cur] == nums[available - 2]) {
                ++cur;
            } else {
                nums[available++] = nums[cur++];
            }
        }
        return available;
    }
};

int main()
{
    vector<int> v = {0,0,1,1,1,1,2,3,3};
    int len = Solution().removeDuplicates(v);
    for (int i = 0; i < len; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}