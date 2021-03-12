#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    inline int max(int a, int b) {
        return a > b ? a : b;
    }

    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<int, int> m;
        int maxCnt = 0, sum;
        for (auto &v : wall) {
            sum = v[0];
            for (int i = 1; i <= v.size() - 1; ++i) {
                ++m[sum];
                maxCnt = max(maxCnt, m[sum]);
                sum += v[i];
            }
        }
        return wall.size() - maxCnt;
    }
};

vector<int> string2int(string str) {
    vector<int> nums;
    int num;
    stringstream sstream(str);
    while (sstream >> num) {
        nums.push_back(num);
    }
    return nums;
}

int main()
{
    vector<vector<int> > wall;
    vector<int> v;
    string aLine;
    int n, k, data;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, aLine);
        v = string2int(aLine);
        wall.push_back(v);
    }
    int res = Solution().leastBricks(wall);
    cout << res << endl;
    return 0;
}