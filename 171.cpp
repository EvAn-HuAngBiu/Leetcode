#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        long long sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            sum = sum * 26 + s[i] - 'A' + 1;
        }
        return sum;
    }
};

int main()
{
    string input;
    cin >> input;
    cout << Solution().titleToNumber(input) << endl;
    return 0;
}