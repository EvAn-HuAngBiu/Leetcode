#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0, result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 0 ? -1 : 1);
            if (m.find(sum) != m.end()) {
                result = max(result, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }
        return result;
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
    cout << Solution().findMaxLength(v) << endl;
    return 0;
}