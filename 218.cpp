#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> all;
        vector<vector<int>> ans;

        for (auto& b : buildings) {
            all.insert(make_pair(b[0], -b[2]));
            all.insert(make_pair(b[1], b[2]));
        }
        multiset<int> height({0});
        vector<int> last = {0, 0};
        for (auto& e : all) {
            if (e.second < 0) {
                height.insert(-e.second);
            } else {
                height.erase(height.find(e.second));
            }
            auto maxHeight = *height.rbegin();
            if (last[1] != maxHeight) {
                last[0] = e.first;
                last[1] = maxHeight;
                ans.emplace_back(last);
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> g[i][0] >> g[i][1] >> g[i][2];
    }
    vector<vector<int>> ans = Solution().getSkyline(g);
    for (auto& c : ans) {
        cout << c[0] << " " << c[1] << endl;
    }
    return 0;
}