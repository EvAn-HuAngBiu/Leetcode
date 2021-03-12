#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    // 滑动窗口，想法1：每次比较滑出的元素和滑入的元素哈希值，用一个set存储失配字符
    // 每次比较正确值和当前值即可，只有当哈希表匹配并且没有失配字符时才记录，否则调整set
    vector<int> findAnagrams1(string s, string p) {
        int ss = s.size(), ps = p.size();
        if (ss < ps) {
            return {};
        }
        map<char, int> right, cur;
        for (int i = 0; i < ps; ++i) {
            ++right[p[i]];
            ++cur[s[i]];
        }
        set<char> unmatched;
        vector<int> result;
        for (auto& it : right) {
            if (cur.find(it.first) == cur.end() || cur[it.first] != it.second) {
                unmatched.insert(it.first);
            }
        }
        if (unmatched.empty()) {
            result.emplace_back(0);
        }
        for (int i = 1; i + ps <= ss; ++i) {
            char pre = s[i - 1];
            --cur[pre];
            char next = s[i + ps - 1];
            ++cur[next];
            if (cur[pre] == right[pre] && cur[next] == right[next]) {
                unmatched.erase(pre);
                unmatched.erase(next);
                if (unmatched.empty()) {
                    result.emplace_back(i);
                    continue;
                }
            }
            if (cur[pre] != right[pre]) {
                unmatched.insert(pre);
            } else {
                unmatched.erase(pre);
            }

            if (cur[next] != right[next]) {
                unmatched.insert(next);
            } else {
                unmatched.erase(next);
            }
        }
        return result;
    }

    // 滑动窗口，想法2：用数组记录即可，每次比较整个数组，由于数组长度固定为52，所以比较的时间复杂度为O(1)
    // 接下来滑动即可，总时间复杂度为O(n - m)，n为s的长度，m为p的长度
    // 额外空间为O(1)
    bool cmp(const int* i1, const int* i2) {
        for (int i = 0; i < 52; ++i) {
            if (i1[i] != i2[i]) {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int right[52] = {0}, cur[52] = {0};
        int ss = s.size(), ps = p.size();
        if (ss < ps) {
            return {};
        }
        for (int i = 0; i < ps; ++i) {
            ++right[p[i] >= 'a' ? p[i] - 'a' : p[i] - 'A'];
            ++cur[s[i] >= 'a' ? s[i] - 'a' : s[i] - 'A'];
        }
        vector<int> result;
        if (cmp(right, cur)) {
            result.emplace_back(0);
        }
        for (int i = 1; i + ps <= ss; ++i) {
            --cur[s[i - 1] >= 'a' ? s[i - 1] - 'a' : s[i - 1] - 'A'];
            ++cur[s[i + ps - 1] >= 'a' ? s[i + ps - 1] - 'a' : s[i + ps - 1] - 'A'];
            if (cmp(right, cur)) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};

int main()
{
    string s, p;
    cin >> s >> p;
    vector<int> v = Solution().findAnagrams(s, p);
    if (v.empty()) {
        cout << "none" << endl;
        return 0;
    }
    for (int i = 0; i < v.size() - 1; ++i) {
        cout << v[i] << " ";
    }
    cout << v[v.size() - 1] << endl;
    return 0;
}