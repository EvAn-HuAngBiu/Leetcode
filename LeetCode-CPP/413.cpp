#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices1(vector<int>& A) {
        int size = A.size();
        if (size < 3) {
            return 0;
        }
        // 表示从[0...i]能够构成的等差数列个数
        vector<int> dp(size, 0);
        // 计算所有区间等差数列的总个数
        int cnt = 0;
        for (int i = 2; i < size; ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = dp[i - 1] + 1;
                cnt += dp[i];
            }
        }
        return cnt;
    }

    int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size();
        if (size < 3) {
            return 0;
        }
        // 在上一个函数中观察可知，dp[i]只与dp[i - 1]相关联，故可以改进
        int pre = 0, cnt = 0;
        for (int i = 2; i < size; ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                pre += 1;
                cnt += pre;
            } else {
                pre = 0;
            }
        }
        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << Solution().numberOfArithmeticSlices(a) << endl;
    return 0;
}