#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static bool cmp(const pair<string, int>& p1, const pair<string, int>& p2) {
        if (p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (auto& s : words) {
            ++m[s];
        }
        vector<pair<string, int>> v;
        copy(m.begin(), m.end(), back_inserter(v));
        sort(v.begin(), v.end(), cmp);
        vector<string> result;
        for_each(v.begin(), v.begin() + k, [&](const pair<string, int>& p){result.emplace_back(p.first);});
        return result;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int k;
    cin >> k;
    vector<string> result = Solution().topKFrequent(v, k);
    if (result.size() == 0) {
        return 0;
    }
    for (int i = 0; i < result.size() - 1; ++i) {
        cout << result[i] << " ";
    }
    cout << result[result.size() - 1] << endl;
    return 0;
}