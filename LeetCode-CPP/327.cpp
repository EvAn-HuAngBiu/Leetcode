#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

// TLE
// int countRangeSum(vector<int>& nums, int lower, int upper) {
//     int size = nums.size();
//     if (!size) {
//         return 0;
//     }
//     vector<long> sum(size);
//     sum[0] = nums[0];
//     long total = nums[0];
//     for (int i = 1; i < size; i++) {
//         sum[i] = total + nums[i];
//         total = sum[i];
//     }
//     int result = 0;
//     for (int i = 0; i < size; i++) {
//         for (int j = i; j < size; j++) {
//             long cur = sum[j] - sum[i] + nums[i];
//             if (cur >= lower && cur <= upper) {
//                 ++result;
//             }
//         }
//     }
//     return result;
// }

int countRangeSum(vector<int>& nums, int lower, int upper) {
    int size = nums.size();
    if (size == 0) {
        return 0;
    }
    int sum = 0, result = 0;
    multiset<int> s;
    s.insert(0);
    for (const int& n : nums) {
        sum += n;
        result += distance(s.lower_bound(sum - upper), s.upper_bound(sum - lower));
        s.insert(sum);
    }
    return result;
}

int merge(vector<long>& sum, int lower, int upper, int low, int high) {
    if (high - low <= 1) {
        return 0;
    }
    int mid = (high + low) / 2, m = mid, n = mid, count = 0;
    count = merge(sum, lower, upper, low, mid) + merge(sum, lower, upper, mid, high);
    for (int i = low; i < mid; i++) {
        while (m < high && sum[m] - sum[i] < lower) m++;
        while (n < high && sum[n] - sum[i] <= upper) n++;
        count += n - m;
    }
    inplace_merge(sum.begin() + low, sum.begin() + mid, sum.begin() + high);
    return count;
}

int countRangeSum2(vector<int>& nums, int lower, int upper) {
    int size = nums.size();
    if (size == 0) {
        return 0;
    }
    vector<long> sum(size + 1, 0);
    for (int i = 1; i <= size; i++) {
        sum[i] = sum[i - 1] + nums[i - 1];
    }
    return merge(sum, lower, upper, 0, size + 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int l, h;
    cin >> l >> h;
    cout << countRangeSum2(v, l, h) << endl;
    return 0;
}