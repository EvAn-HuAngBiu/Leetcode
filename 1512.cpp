#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> m;
        for (const int& i : nums) {
            ++m[i];
        }
        int result = 0;
        for (const auto& k : m) {
            result += k.second * (k.second - 1) / 2;
        }
        return result;
    }
};

int main()
{
    return 0;
}