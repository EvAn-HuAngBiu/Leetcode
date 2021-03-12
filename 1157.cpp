#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class MajorityChecker
{
private:
    unordered_map<int, vector<int>> m;
public:
    MajorityChecker(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            m[arr[i]].emplace_back(i);
        }
    }
    int query(int left, int right, int threshold)
    {
        for (auto &c : m)
        {
            if (c.second.size() < threshold)
            {
                continue;
            }
            // 索引必定有序，利用二分查找索引起始位置和结束位置，相减就是个数了
            auto l = lower_bound(c.second.begin(), c.second.end(), left);
            auto r = upper_bound(c.second.begin(), c.second.end(), right);
            if (r - l >= threshold)
            {
                return c.first;
            }
        }
        return -1;
    }
};


int main()
{
    int n, a, m, left, right, threshold;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    MajorityChecker mc(arr);
    cin >> m;
    for (int i = 0; i < m; i++)
    { //在IDE中运行时，输入和输出会交错，这是正常现象
        cin >> left;
        cin >> right;
        cin >> threshold;
        int res = mc.query(left, right, threshold);
        cout << res << " ";
    }
}