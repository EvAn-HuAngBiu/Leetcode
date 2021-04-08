#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int singleNumber1(vector<int>& nums) {
        unordered_set<int> s;
        for (auto& n : nums) {
            if (s.find(n) == s.end()) {
                s.insert(n);
            } else {
                s.erase(n);
            }
        }
        return *s.begin();
    }

    int singleNumber(vector<int>& nums) {
        // 利用位运算：异或
        int cur = 0;
        for (auto& n : nums) {
            cur ^= n;
        }
        return cur;
    }
};

int main()
{
    vector<int> v = {4, 1, 2, 1, 2};
    cout << Solution().singleNumber(v) << endl;
    return 0;
}