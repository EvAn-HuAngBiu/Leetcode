#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int calSum(int n) {
        int sum = 0, bit;
        while (n) {
            bit = n % 10;
            sum += bit * bit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> val;
        while (n != 1) {
            if (val.find(n) != val.end()) {
                return false;
            }
            val.insert(n);
            n = calSum(n);
        }
        return true;
    }
};

int main()
{
    cout << boolalpha << Solution().isHappy(19) << endl;
    return 0;
}