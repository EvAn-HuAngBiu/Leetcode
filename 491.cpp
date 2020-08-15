#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    int size;
    void dfs(const vector<int>& nums, vector<int>& cur, int index) {
        if (cur.size() >= 2) {
            result.emplace_back(vector<int>(cur));
        }
        set<int> dup;
        for (int i = index; i < size; ++i) {
            if (!cur.empty() && nums[i] < cur.back()) {
                continue;
            }
            if (dup.find(nums[i]) == dup.end()) {
                dup.insert(nums[i]);
                cur.emplace_back(nums[i]);
                dfs(nums, cur, i + 1);
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        size = nums.size();
        if (!size) {
            return {};
        }
        vector<int> cur;
        dfs(nums, cur , 0);
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
    vector<vector<int>> result = Solution().findSubsequences(v);
    for (auto& r : result) {
        for (auto& p : r) {
            cout << p << " ";
        }
        cout << endl;
    }
    return 0;
}