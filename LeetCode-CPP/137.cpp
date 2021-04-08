#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto& n : nums) {
            ++m[n];
        }
        for (auto& p : m) {
            if (p.second == 1) {
                return p.first;
            }
        }
    }
};

int main()
{
    return 0;
}