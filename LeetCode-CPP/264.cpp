#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int prime[] = {2, 3, 5};
        int record[3] = {0};
        vector<long long> ugly(n, 0x7fffffff);
        ugly[0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                while (prime[j] * ugly[record[j]] <= ugly[i - 1]) {
                    ++record[j];
                }
                ugly[i] = min(ugly[i], prime[j] * ugly[record[j]]);
            }
        }
        return ugly[n - 1];
    }
};

int main()
{
    cout << Solution().nthUglyNumber(10) << endl;
    return 0;
}