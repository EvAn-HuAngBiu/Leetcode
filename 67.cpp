#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int as = a.size(), bs = b.size();
        if (as > bs) {
            b.insert(0, as - bs, '0');
        } else {
            a.insert(0, bs - as, '0');
        }
        as = a.size();
        vector<int> result(as + 1, 0);
        for (int i = as - 1; i >= 0; --i) {
            result[i + 1] += a[i] - '0' + b[i] - '0';
            result[i] += result[i + 1] / 2;
            result[i + 1] %= 2;
        }
        string r;
        if (result[0] != 0) {
            r += "1";
        }
        for (int i = 1; i <= as; ++i) {
            r += to_string(result[i]);
        }
        return r;
    }
};

int main()
{
    cout << Solution().addBinary("1010", "1011") << endl;
    return 0;
}