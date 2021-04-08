#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<string, vector<string>> map;
public:
    bool dfs(vector<string> &cur, int cnt, int level) {
        if (cur.size() == 1) {
            return true;
        }
        string prefix = cur[0] + cur[1];
        if (map.find(prefix) == map.end()) {
            return false;
        }
        string front = cur[0];
        cur.erase(cur.begin());
        for (auto &s : map[prefix]) {
            cur.emplace_back(s);
            if (cnt == level - 1) {
                string fr2 = cur[0];
                cur.erase(cur.begin());
                if (dfs(cur, 1, level - 1)) {
                    return true;
                }
                cur.insert(cur.begin(), fr2);
            } else {
                if (dfs(cur, cnt + 1, level)) {
                    return true;
                }
            }
            cur.pop_back();
        }
        cur.insert(cur.begin(), front);
        return false;
    }

    bool pyramidTransition(string bottom, vector<string> &allowed) {
        for (auto &str : allowed) {
            map[str.substr(0, 2)].emplace_back(str.substr(2));
        }
        vector<string> cur;
        for (auto &c : bottom) {
            cur.emplace_back(string(1, c));
        }
        return dfs(cur, 1, cur.size());
    }
};

int main() {
    string bottom, rule;
    vector<string> allowed;
    cin >> bottom;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> rule;
        allowed.push_back(rule);
    }
    bool res = Solution().pyramidTransition(bottom, allowed);
    cout << boolalpha << res << endl;
    return 0;
}