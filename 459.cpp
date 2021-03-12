#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        for (int i = 1; i <= size / 2; ++i) {
            if (size % i == 0) {
                string split = s.substr(0, i);
                string cur = split;
                for (int j = 1; j < size / i; ++j) {
                    cur += split;
                }
                if (cur == s) {
                    return true;
                }
            }
        }
        return false;
        // return (s + s).find(s, 1) != s.size();
    }
};

int main()
{
    cout << boolalpha << Solution().repeatedSubstringPattern("abcabcabc") << endl;
    return 0;
}