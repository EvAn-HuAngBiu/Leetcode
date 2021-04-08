#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0, size = s.size();
        for (int i = 0; i < size; ++i) {
            int p = 0;
            while (i - p >= 0 && i + p < size && s[i - p] == s[i + p]) {
                ++p;
                ++ans;
            }
        }
        for (int i = 0; i < size - 1; ++i) {
            if (s[i] == s[i + 1]) {
                int p = 0;
                while (i - p >= 0 && i + p + 1 < size && s[i - p] == s[i + p + 1]) {
                    ++p;
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}