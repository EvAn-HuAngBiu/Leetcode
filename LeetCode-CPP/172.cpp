#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        for (int i = 5; i <= n; i += 5) {
            int cur = i;
            while (cur % 5 == 0) {
                ++cnt;
                cur /= 5;
            }
        }
        return cnt;
    }
};

int main()
{
    cout << Solution().trailingZeroes(3) << endl;
    return 0;
}