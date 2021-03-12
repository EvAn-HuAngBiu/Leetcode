#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

bool dfs(const vector<int>& nums, vector<int>& v, int index, const int& maxSum) {
    if (nums.size() == index) {
        return true;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i] + nums[index] <= maxSum) {
            v[i] += nums[index];
            if (dfs(nums, v, index + 1, maxSum)) {
                return true;
            }
            v[i] -= nums[index];
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    vector<int> v(k, 0);
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    int sum = accumulate(nums.begin(), nums.end(), 0), maxSum = sum / k;
    if (sum % k) {
        return false;
    }
    return dfs(nums, v, 0, maxSum);
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> k;
    cout << boolalpha << canPartitionKSubsets(v, k) << endl;
    return 0;
}