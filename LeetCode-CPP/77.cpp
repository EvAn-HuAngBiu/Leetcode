#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int> v, int k, int n, int next) {
        if (v.size() == k) {
            result.emplace_back(v);
            return;
        }
        if (n - next + 1 < k - v.size()) {
            return;
        }
        dfs(v, k, n, next + 1);
        v.push_back(next);
        dfs(v, k, n, next + 1);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        dfs(v, k, n, 1);
        return result;
    }
};

int main()
{
    vector<vector<int>> v = Solution().combine(4, 2);
    for (auto& c : v) {
        for (auto& i : c) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}