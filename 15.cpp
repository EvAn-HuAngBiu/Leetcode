#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

struct Tuple {
    vector<int> v;
    Tuple() {}
    Tuple(int a, int b, int c) {
        v = vector<int>{a, b, c};
    }

    bool operator<(const Tuple& t) const {
        if (v[0] == t.v[0] && v[1] == t.v[1] && v[2] == t.v[2]) {
            return false;
        }
        if (v[0] == t.v[0]) {
            if (v[1] == t.v[1]) {
                return v[2] < t.v[2];
            }
            return v[1] < t.v[1];
        }
        return v[0] < t.v[0];
    }
};

class Solution {
public:
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     set<Tuple> t;
    //     int size = nums.size(), sum;
    //     sort(nums.begin(), nums.end());
    //     for (int i = 0; i < size; ++i) {
    //         sum = nums[i];
    //         for (int j = i + 1; j < size; ++j) {
    //             sum += nums[j];
    //             if (sum > 0) {
    //                 break;
    //             }
    //             for (int k = j + 1; k < size; ++k) {
    //                 if (sum + nums[k] == 0) {
    //                     t.insert(Tuple(nums[i], nums[j], nums[k]));
    //                 } else if (sum + nums[k] > 0) {
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     vector<vector<int>> result;
    //     for (const Tuple& c : t) {
    //         result.emplace_back(c.v);
    //     }
    //     return result;
    // }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        if (size < 3) {
            return {};
        }
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int p, q;
        for (int i = 0; i < size; ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            p = i + 1;
            q = size - 1;
            while (p < q) {
                int sum = nums[i] + nums[p] + nums[q];
                if (sum == 0) {
                    result.emplace_back(vector<int>{nums[i], nums[p], nums[q]});
                    while (p < q && nums[p] == nums[p + 1]) {
                        ++p;
                    }
                    while (p < q && nums[q] == nums[q - 1]) {
                        --q;
                    }
                    ++p;
                    --q;
                } else if (sum > 0) {
                    --q;
                } else {
                    ++p;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> v = {-1,0,1,2,-1,-4};
    vector<vector<int>> vv = Solution().threeSum(v);
    for (const vector<int> c : vv) {
        cout << c[0] << ", " << c[1] << ", " << c[2] << endl;
    }
    return 0;
}