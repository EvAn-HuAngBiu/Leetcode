#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.emplace_back(vector<int>());
        for (auto& num : nums) {
            int size = result.size();
            for (int i = 0; i < size; ++i) {
                vector<int> cur(result[i]);
                cur.emplace_back(num);
                result.emplace_back(cur);
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}