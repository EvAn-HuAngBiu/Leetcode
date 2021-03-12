#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;

    void dfs(const vector<int>& nums, vector<int> &cur, int n) {
        result.emplace_back(vector<int>(cur));
        set<int> dup;
        for (int i = n; i < nums.size(); ++i) {
            if (dup.find(nums[i]) == dup.end()) {
                cur.emplace_back(nums[i]);
                dup.insert(nums[i]);
                dfs(nums, cur, i + 1);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        dfs(nums, cur, 0);
        return result;
    }
};

int main()
{
    vector<int> input = {1, 2, 2};
    vector<vector<int>> result = Solution().subsetsWithDup(input);
    for (auto& v : result) {
        for (auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}