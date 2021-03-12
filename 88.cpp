#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m - 1, q = n - 1, ava = m + n - 1;
        while (p >= 0 && q >= 0) {
            if (nums1[p] >= nums2[q]) {
                nums1[ava--] = nums1[p--]; 
            } else {
                nums1[ava--] = nums2[q--];
            }
        }
        if (p < 0) {
            for (int i = 0; i <= q; ++i) {
                nums1[i] = nums2[i];
            }
        }
    }
};

int main()
{
    vector<int> v1 = {0}, v2 = {1};
    Solution().merge(v1, 0, v2, 1);
    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << " ";
    }
    cout << endl;
    return 0;
}