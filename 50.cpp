#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        long b = n;
        if (n < 0) {
            x = 1 / x;
            b = -b;
        }
        double result = 1;
        while (b) {
            if (b % 2) {
                result *= x;
            }
            x *= x;
            b /= 2;
        }
        return result;
    }
};

int main()
{
    cout << Solution().myPow(2.00000, -2) << endl;
    return 0;
}