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
        for (int i = 0; i < size; ++i) {
            if (!visit[i]) {
                visit[i] = true;
                cur.emplace_back(nums[i]);
                dfs(nums, cur, visit);
                visit[i] = false;
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> permute1(vector<int>& nums) {
        size = nums.size();
        if (!size) {
            return {};
        }
        for (int i = 0; i < size; ++i) {
            vector<int> cur;
            cur.emplace_back(nums[i]);
            vector<bool> visit(size, false);
            visit[i] = true;
            dfs(nums, cur, visit);
        }
        return result;
    }

    // 方法2
    void swap(vector<int>& nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    void next_perm(vector<int>& nums, int beg, int end) {
        if (beg == end) {
            result.emplace_back(vector<int>(nums));
            return;
        }
        for (int i = beg; i <= end; ++i) {
            swap(nums, beg, i);
            next_perm(nums, beg + 1, end);
            swap(nums, beg, i);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        next_perm(nums, 0, nums.size() - 1);
        return result;
    }
};

int main()
{
    vector<int> v = {1, 2, 3};
    vector<vector<int>> vv = Solution().permute(v);
    for (const auto& c : vv) {
        for (const auto& i : c) {
            cout << i << ", ";
        }
        cout << endl;
    }
    return 0;
}