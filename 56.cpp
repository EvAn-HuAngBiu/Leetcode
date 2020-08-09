#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        if (v1[0] == v2[0]) {
            return v2[1] < v2[1];
        }
        return v1[0] < v2[0];
    }

    vector<int> mergeHelper(const vector<int>& a, const vector<int>& b) {
        if (b[0] > a[1]) {
            return {};
        }
        return {a[0], max(a[1], b[1])};
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (!size) {
            return {};
        }
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> stack;
        for (int i = 0; i < size; ++i) {
            if (stack.empty()) {
                stack.emplace_back(intervals[i]);
            } else {
                vector<int> cur = mergeHelper(stack.back(), intervals[i]);
                if (cur.empty()) {
                    stack.emplace_back(intervals[i]);
                } else {
                    stack.pop_back();
                    stack.emplace_back(cur);
                }
            }
        }
        return stack;
    }
};

int main()
{
    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = Solution().merge(v);
    for (auto& p : result) {
        cout << p[0] << " " << p[1] << endl;
    }
    return 0;
}