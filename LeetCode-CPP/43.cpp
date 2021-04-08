#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size(), l2 = num2.size();
        vector<int> result(l1 + l2, 0);
        for (int i = 0; i < l1; ++i) {
            for (int j = 0; j < l2; ++j) {
                result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = l1 + l2 - 1; i >= 1; --i) {
            result[i - 1] += result[i] / 10;
            result[i] %= 10;
        }
        string r;
        bool nonZero = false;
        if (result[0] != 0) {
            nonZero = true;
            r += to_string(result[0]);
        }
        for (int i = 1; i < l1 + l2; ++i) {
            if (result[i] != 0) {
                nonZero = true;
            }
            r += to_string(result[i]);
        }
        return nonZero ? r : "0";
    }
};

int main()
{
    cout << Solution().multiply("9133", "0") << endl;
    return 0;
}