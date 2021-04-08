#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n) {
            --n;
            result += 'A' + n % 26;
            n /= 26;
        };
        reverse(begin(result), end(result));
        return result;
    }
};

int main()
{
    cout << Solution().convertToTitle(701) << endl;
    return 0;
}