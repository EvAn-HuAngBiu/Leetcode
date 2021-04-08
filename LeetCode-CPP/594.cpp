#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    inline int max(int a, int b) {
        return a > b ? a : b;
    }

    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto& i : nums) {
            ++m[i];
        }
        int maxVal = 0;
        for (auto& it : m) {
            if (m.find(it.first + 1) != m.end()) {
                maxVal = max(maxVal, it.second + m[it.first + 1]);
            }
        }
        return maxVal;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << Solution().findLHS(v) << endl;
    return 0;
}