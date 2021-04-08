#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) {
            return 0;
        }
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return count_if(isPrime.begin(), isPrime.end(), [&](bool a){return a;});
    }
};

int main()
{
    cout << Solution().countPrimes(10) << endl;
    return 0;
}