#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int s1 = haystack.size(), s2 = needle.size();
        if (!s2) {
            return 0;
        }
        for (int i = 0; i + s2 <= s1; i++) {
            if (haystack.substr(i, s2) == needle) {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}