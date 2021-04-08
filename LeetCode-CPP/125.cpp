#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int p = 0, q = s.size() - 1;
        while (p < q) {
            if (isalnum(s[p]) && isalnum(s[q])) {
                if (tolower(s[p]) != tolower(s[q])) {
                    return false;
                }
                ++p;
                --q;
            } else if (!isalnum(s[p])) {
                ++p;
            } else {
                --q;
            }
        }
        return true;
    }
};

int main()
{
    cout << boolalpha << Solution().isPalindrome("race a car") << endl;
    return 0;
}