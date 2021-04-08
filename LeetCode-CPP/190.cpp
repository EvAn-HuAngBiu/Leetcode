#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t sum = 0;
        int power = 31;
        while (n) {
            sum += (n & 1) << power;
            n >>= 1;
            --power;
        }
        return sum;
    }
};

int main()
{
    cout << Solution().reverseBits(43261596) << endl;
    return 0;
}