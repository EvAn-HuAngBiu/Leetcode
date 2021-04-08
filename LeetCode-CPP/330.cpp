#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

//int minPatches(vector<int>& nums, int n) {
//    set<long> window;
//    for (int i = 0; i < nums.size(); i++) {
//        set<long> temp;
//        for (set<long>::iterator it = window.begin(); it != window.end(); it++) {
//            temp.insert(nums[i] + *it);
//        }
//        window.insert(temp.begin(), temp.end());
//        window.insert(nums[i]);
//    }
//    long cur = 1, cnt = 0;
//    while (cur <= n) {
//        if (window.find(cur) != window.end()) {
//            cur++;
//        } else {
//            set<long> temp;
//            for (set<long>::iterator it = window.begin(); it != window.end(); it++) {
//                temp.insert(cur + *it);
//            }
//            window.insert(temp.begin(), temp.end());
//            window.insert(cur++);
//            ++cnt;
//        }
//    }
//    return cnt;
//}

int minPatches(vector<int>& nums, int n) {
    int size = nums.size(), index = 0, cnt = 0;
    long long cur = 1;
    while (cur <= n) {
        if (index < size && nums[index] <= cur) {
            cur += nums[index++];
        } else {
            ++cnt;
            cur += cur;
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int k;
    cin >> k;
    cout << minPatches(v, k) << endl;
    return 0;
}