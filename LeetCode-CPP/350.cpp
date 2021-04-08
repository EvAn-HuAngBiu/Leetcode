#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int p = 0, q = 0;
    vector<int> result;
    while (p < nums1.size() && q < nums2.size()) {
        if (nums1[p] == nums2[q]) {
            result.push_back(nums1[p]);
            p++;
            q++;
        } else if (nums1[p] > nums2[q]) {
            q++;
        } else {
            p++;
        }
    }
    return result;
}

int main()
{
    vector<int> v1 = {4,9,5}, v2 = {9,4,9,8,4};
    for (const int& i : intersect(v1, v2)) {
        cout << i << endl;
    }
    return 0;
}