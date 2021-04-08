#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if (size <= 2) {
            return 0;
        }
        int pre1 = cost[1], pre2 = cost[0];
        for (int i = 2; i < size; ++i) {
            int cur = min(pre1, pre2) + cost[i];
            pre2 = pre1;
            pre1 = cur;
        }
        return min(pre1, pre2);
    }
};

int main()
{
    vector<int> v = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << Solution().minCostClimbingStairs(v) << endl;
    return 0;
}