#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int size;
    vector<vector<int>> result;

    void dfs(const vector<int>& nums, vector<int>& cur, vector<bool>& visit) {
        if (cur.size() == size) {
            result.emplace_back(vector<int>(cur));
            return;
        }
        int last = INT_MIN;
        for (int i = 0; i < size; ++i) {
            if (!visit[i]) {
                if (last == nums[i]) {
                   continue;
                }
                last = nums[i];
                visit[i] = true;
                cur.emplace_back(nums[i]);
                dfs(nums, cur, visit);
                visit[i] = false;
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        size = nums.size();
        if (!size) {
            return {};
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            vector<int> cur;
            cur.emplace_back(nums[i]);
            vector<bool> visit(size, false);
            visit[i] = true;
            dfs(nums, cur, visit);
        }
        return result;
    }
};

int main()
{
    vector<int> v = {1, 1, 2};
    vector<vector<int>> vv = Solution().permute(v);
    for (const auto& c : vv) {
        for (const auto& i : c) {
            cout << i << ", ";
        }
        cout << endl;
    }
    return 0;
}