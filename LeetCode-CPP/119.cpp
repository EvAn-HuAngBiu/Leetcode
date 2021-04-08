#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (!rowIndex) {
            return {1};
        }
        vector<int> pre = {1};
        for (int i = 1; i <= rowIndex; ++i) {
            vector<int> cur(i + 1);
            cur[0] = 1;
            for (int j = 0; j < i - 1; ++j) {
                cur[j + 1] = pre[j] + pre[j + 1];
            }
            cur[i] = 1;
            pre = cur;
        }
        return pre;
    }
};

int main()
{
    for (auto& v : Solution().getRow(5)) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}