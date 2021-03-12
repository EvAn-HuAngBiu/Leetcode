#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<string> g(int n) {
        if (n == 0) {
            return {"0"};
        } else if (n == 1) {
            return {"0", "1"};
        }
        vector<string> gn = g(n - 1);
        vector<string> result(gn);
        for (auto& r : result) {
            r.insert(0, "0");
        }
        for (auto it = gn.rbegin(); it != gn.rend(); ++it) {
            result.emplace_back("1" + *it);
        }
        return result;
    }

    int str2Int(string s) {
        int size = s.size() - 1;
        int result = 0, time = 0;
        for (int i = size; i >= 0; --i) {
            result += pow(2, time++) * (s[i] - '0');
        }
        return result;
    }

    vector<int> grayCode(int n) {
        vector<string> cur = g(n);
        vector<int> result(cur.size());
        for (int i = 0; i < cur.size(); ++i) {
            result[i] = str2Int(cur[i]);
        }
        return result;
    }
};

int main()
{
    vector<int> v = Solution().grayCode(2);
    for (auto& i : v) {
        cout << i << endl;
    }
    return 0;
}