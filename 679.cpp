#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool select(vector<double>& cur) {
        int size = cur.size();
        if (size == 1) {
            return fabs(cur.front() - 24) <= 1e-6;
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i != j) {
                    double a = cur[i], b = cur[j];
                    vector<double> next;
                    for (int k = 0; k < size; ++k) {
                        if (k != i && k != j) {
                            next.emplace_back(cur[k]);
                        }
                    }
                    next.emplace_back(a + b);
                    if (select(next)) {
                        return true;
                    }
                    next.pop_back();

//                if (a > b) {
                    next.emplace_back(a - b);
                    if (select(next)) {
                        return true;
                    }
                    next.pop_back();
//                }

                    next.emplace_back(a * b);
                    if (select(next)) {
                        return true;
                    }
                    next.pop_back();

                    if (b != 0) {
                        next.emplace_back(a / b);
                        if (select(next)) {
                            return true;
                        }
                        next.pop_back();
                    }
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return false;
        } else if (size == 1) {
            return nums.front() == 24;
        }
        vector<double> n(nums.begin(), nums.end());
        return select(n);
    }
};

int main()
{
    vector<int> v = {8, 1, 6, 6};
    cout << boolalpha << Solution().judgePoint24(v) << endl;
    return 0;
}