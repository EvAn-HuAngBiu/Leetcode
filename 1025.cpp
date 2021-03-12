#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        int round = 0;
        for (int x = 1; x < N; x++) {
            if (N % x == 0) {
                N -= x;
                round++;
            }
        }
        return round % 2;
    }
};

int main()
{
    int n;
    cin >> n;
    cout << Solution().divisorGame(n) << endl;
    return 0;
}