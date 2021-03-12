#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        ++digits[size - 1];
        int p = size - 1;
        while (p > 0 && digits[p] >= 10) {
            digits[p - 1] += 1;
            digits[p] -= 10;
            --p;
        }
        if (digits[0] >= 10) {
            digits[0] -= 10;
            digits.emplace(digits.begin(), 1);
        }
        return digits;
    }
};

int main()
{
    vector<int> d = {9, 9, 9};
    for (int p : Solution().plusOne(d)) {
        cout << p << endl;
    }
    return 0;
}