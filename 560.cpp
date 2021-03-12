#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, size = nums.size(), sum;
        for (int i = 0; i < size; ++i) {
            sum = 0;
            for (int j = i; j < size; ++j) {
                sum += nums[j];
                if (sum == k) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int k;
    cin >> k;
    cout << Solution().subarraySum(v, k) << endl;
    return 0;
}