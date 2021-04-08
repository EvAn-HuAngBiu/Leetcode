#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> findMax(const vector<int>& v, int k) {
    vector<int> stack;
    int size = v.size();
    for (int i = 0; i < size; i++) {
        while (!stack.empty() && v[i] > stack.back() && size - i >= k - stack.size() + 1) {
            stack.pop_back();
        }
        if (stack.size() < k) {
            stack.push_back(v[i]);
        }
    }
    return stack;
}

bool cmp(const vector<int>& nums1, int i, const vector<int>& nums2, int j){
    while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]){
        i++;
        j++;
    }
    return j == nums2.size() || (i<nums1.size() && nums1[i] > nums2[j]);
}

vector<int> merge(const vector<int>& v1, const vector<int>& v2, int k) {
    vector<int> result(k);
    int p = 0, q = 0;
    for (int i = 0; i < k; i++) {
        if(cmp(v1, p, v2, q)) {
            result[i] = v1[p++] ;
        }
        else result[i] = v2[q++];

    }
    return result;
}

bool cmp(const vector<int>& v1, const vector<int>& v2) {
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] < v2[i]) {
            return false;
        } else if (v1[i] > v2[i]) {
            return true;
        }
    }
    return false;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> m(k);
    for (int i = 0; i <= min(k, nums1.size()); i++) {
        if (i <= nums1.size() && k - i <= nums2.size()) {
            vector<int> r = merge(findMax(nums1, i), findMax(nums2, k - i), k);
            m = cmp(r, m) ? r : m;
        }
    }
    return m;
}

int main()
{
    vector<int> v1 = {3, 4, 6, 5}, v2 = {9, 1, 2, 5, 8, 3};
    for (const int& i : maxNumber(v1, v2, 5)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}