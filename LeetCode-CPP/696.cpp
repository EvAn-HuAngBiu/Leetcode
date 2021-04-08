#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int size = s.size(), cnt = 0, last = 0;
        for (int i = 0; i < size;) {
            char c = s[i];
            int cur = 0;
            while (i < size && s[i] == c) {
                ++i;
                ++cur;
            }
            cnt += min(cur, last);
            last = cur;
        }
        return cnt;
    }
};

int main()
{
    cout << Solution().countBinarySubstrings("10101") << endl;
    return 0;
}