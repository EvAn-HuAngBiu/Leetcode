#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string loop(string val, int round) {
        if (round == 1) {
            return val;
        }
        string result;
        char pre = val[0];
        int count = 1, size = val.size();
        for (int i = 1; i < size; i++) {
            if (val[i] == pre) {
                ++count;
            } else {
                result += to_string(count) + pre;
                pre = val[i];
                count = 1;
            }
        }
        result += to_string(count) + pre;
        return loop(result, round - 1);
    }

    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        return loop("1", n);
    }
};

int main()
{
    int n;
    cin >> n;
    cout << Solution().countAndSay(n) << endl;
    return 0;
}