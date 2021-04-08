#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    inline int min(int a, int b) {
        return a < b ? a : b;
    }

    string preHandle(string a) {
        string trans = "^";
        for (const char& c : a) {
            trans += '#';
            trans += c;
        }
        return trans + "#$";
    }

    string longestPalindrome(string s) {
        int size = s.size();
        if (size == 0) {
            return string();
        }
        string t = preHandle(s);
        size = t.size();
        int C = 0, R = 0;
        vector<int> P(size, 0);
        int max = INT_MIN, mid;
        for (int i = 1; i < size - 1; ++i) {
            int i_mirror = 2 * C - i;
            if (R > i) {
                P[i] = min(P[i_mirror], R - i);
            } else {
                P[i] = 0;
            }

            while (t[i + 1 + P[i]] == t[i - 1 - P[i]]) {
                ++P[i];
            }

            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
            if (P[i] > max) {
                max = P[i];
                mid = i;
            }
        }
        return s.substr((mid - max) / 2, max);
    }
};

int main()
{
    cout << Solution().longestPalindrome("babad") << endl;
    return 0;
}