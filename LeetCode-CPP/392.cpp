#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0, q = 0;
        int ss = s.size(), ts = t.size();
        while (p < ss) {
            while (q < ts && t[q] != s[p]) {
                q++;
            }
            if (q < ts) {
                ++p;
                ++q;
            } else {
                return false;
            }
        }
        return p == ss;
    }
};

int main()
{
    cout << boolalpha << Solution().isSubsequence("acb", "aabvac") << endl;
    return 0;
}