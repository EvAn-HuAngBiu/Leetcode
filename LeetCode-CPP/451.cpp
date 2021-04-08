#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool cmp(const pair<char, int>& p1, const pair<char, int>& p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for (const char& c : s) {
            ++m[c];
        }
        vector<pair<char, int>> v;
        copy(m.begin(), m.end(), back_inserter(v));
        sort(v.begin(), v.end(), cmp);
        string result;
        for (auto& p : v) {
            result.append(string(p.second, p.first));
        }
        return result;
    }
};

int main()
{
    cout << Solution().frequencySort("tree") << endl;
    return 0;
}