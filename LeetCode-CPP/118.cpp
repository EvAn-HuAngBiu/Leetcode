#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (!numRows) {
            return {};
        } else if (numRows == 1) {
            return {{1}};
        }
        vector<vector<int>> result(numRows);
        result[0] = {1};
        for (int i = 1; i < numRows; ++i) {
            vector<int>& cur = result[i];
            cur.resize(i + 1);
            cur[0] = 1;
            const vector<int>& back = result[i - 1];
            for (int j = 0; j < i - 1; ++j) {
                cur[j + 1] = back[j] + back[j + 1];
            }
            cur[i] = 1;
        }
        return result;
    }
};

int main()
{
    auto result = Solution().generate(5);
    for (auto& r : result) {
        for (auto& v : r) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}