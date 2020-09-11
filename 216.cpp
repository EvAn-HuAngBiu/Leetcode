#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    int k;
public:
    void dfs(vector<int>& path, int next, int target) {
        if (target == 0 && path.size() == k) {
            result.emplace_back(path);
            return;
        } else if (target < 0 || path.size() == k) {
            return;
        }
        for (int i = next; i <= 9; ++i) {
            path.emplace_back(i);
            dfs(path, i + 1, target - i);
            path.pop_back();
            if (target - i <= 0) {
                break;
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        vector<int> path;
        dfs(path, 1, n);
        return result;
    }
};

int main()
{
    for (auto& v : Solution().combinationSum3(3, 9)) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}