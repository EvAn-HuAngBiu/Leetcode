#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void swap(vector<int>& v, int a, int b) {
        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;
    }

    void sortColors(vector<int>& nums) {
        int size = nums.size();
        if (!size) {
            return;
        }
        int p = 0, q = size - 1;
        while (p < size && nums[p] == 0) {
            ++p;
        }
        while (q >= 0 && nums[q] == 2) {
            --q;
        }
        while (p < q) {
            if (nums[p] > nums[q]) {
                swap(nums, p, q);
            } else if (nums[p] == nums[q]) {
                int r = p + 1;
                while (r < q && nums[r] != 0) {
                    ++r;
                }
                if (r < q) {
                    swap(nums, p, r);
                } else {
                    ++p;
                }
            }
            while (p < size && nums[p] == 0) {
                ++p;
            }
            while (q >= 0 && nums[q] == 2) {
                --q;
            }
        }
    }
};

int main()
{
    vector<int> v = {0, 1, 1, 2, 1, 1, 1, 2};
    Solution().sortColors(v);
    for (auto& i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}