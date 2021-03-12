#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

vector<vector<int>> result;
void dfs(const vector<int>& can, int target, vector<int>& path, int beg) {
    if (target == 0) {
        result.push_back(path);
        return;
    } else if (target < 0) {
        return;
    }
    for (int i = beg; i < can.size(); i++) {
        if (i > beg && can[i - 1] == can[i]) {
            continue;
        }
        if (target >= 0) {
            path.push_back(can[i]);
            dfs(can, target - can[i], path, i + 1);
            path.pop_back();
        } else {
            break;
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> v;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, v, 0);
    return result;
}

int main()
{
    vector<int> v = {10,1,2,7,6,1,5};
    const vector<vector<int>> &result = combinationSum2(v, 8);
    for (auto& r : result) {
        for (auto& i : r) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}