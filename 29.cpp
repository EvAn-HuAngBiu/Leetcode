#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    long div(long a, long b) {
        if (a < b) {
            return 0;
        }
        long time = 1;
        long sum = b;
        while ((sum + sum) < a) {
            sum += sum;
            time += time;
        }
        if (sum != a) {
            return time + div(a - sum, b);
        }
        return time;
    }

    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }
        bool sign = (divisor < 0) ^ (dividend < 0);
        long time = div(abs(long(dividend)), abs(long(divisor)));
        return time > INT_MAX ? INT_MAX : time * (sign ? -1 : 1);
    }
};

int main()
{
    cout << Solution().divide(-2147483648, 2) << endl;
    return 0;
}