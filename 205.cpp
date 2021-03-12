#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return judge(s, t) && judge(t, s);
    }

    bool judge(string s, string t) {
        unordered_map<char, char> m;
        int sa = s.size(), st = t.size();
        if (sa != st) {
            return false;
        }
        for (int i = 0; i < sa; ++i) {
            if (m.find(s[i]) != m.end()) {
                if (m[s[i]] != t[i]) {
                    return false;
                }
            } else {
                m[s[i]] = t[i];
            }
        }
        return true;
    }
};

int main()
{
    cout << boolalpha << Solution().isIsomorphic("paper", "title") << endl;
    return 0;
}