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

    string addStrings(string num1, string num2) {
        int s1 = num1.size(), s2 = num2.size(), len = min(s1, s2);
        vector<int> result(len + 1, 0);
        if (s1 > s2) {
            num2.insert(0, string(s1 - s2, '0'));
        } else {
            num1.insert(0, string(s2 - s1, '0'));
        }
        for (int i = len - 1; i >= 0; --i) {
            result[i + 1] += num1[i] + num2[i] - '0' - '0';
            result[i] += result[i + 1] / 10;
            result[i + 1] %= 10;
        }
        string s;
        if (result[0] == 1) {
            s += '1';
        }
        for (int i = 1; i <= len; ++i) {
            s += to_string(result[i]);
        }
        return s;
    }
};

int main()
{
    cout << Solution().addStrings("12345", "234") << endl;
    return 0;
}