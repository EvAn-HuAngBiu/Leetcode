#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int prime[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        unordered_map<double, vector<string>> m;
        for (const string& str : strs) {
            double temp = 1;
            for (const char& c : str) {
                temp *= prime[c - 'a'];
            }
            m[temp].emplace_back(str);
        }
        vector<vector<string>> vv;
        for (const pair<double, vector<string>>& p : m) {
            vv.emplace_back(p.second);
        }
        return vv;
    }
};

int main()
{
    vector<string> s = {"huh", "tit"};
    for (const vector<string>& vs : Solution().groupAnagrams(s)) {
        for (const string& s : vs) {
            cout << s << " ";
        }
        cout << endl;

    }
    return 0;
}