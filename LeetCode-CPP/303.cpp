#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        sum.assign(nums.size(), 0);
        int s = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i];
            sum[i] = s;
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) {
            return sum[j];
        }
        return sum[j] - sum[i - 1];
    }
};

int main()
{
    vector<int> v = {-2, 0, 3, -5, 2, -1};
    NumArray* n = new NumArray(v);
    cout << n->sumRange(2, 5) << endl;
    return 0;
}