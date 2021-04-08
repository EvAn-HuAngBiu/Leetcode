#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    struct cmp
    {
        bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
        {
            int sum1 = p1.first + p1.second, sum2 = p2.first + p2.second;
            if (sum1 == sum2) {
                if (p1.first == p2.first) {
                    return p1.second > p2.second;
                }
                return p1.first > p2.first;
            }
            return sum1 > sum2;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        if (nums1.size() == 0 || nums2.size() == 0) {
            return vector<vector<int>>();
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (pq.size() <= k)
                {
                    pq.push(pair<int, int>(nums1[i], nums2[j]));
                }
                else
                {
                    int sum = nums1[i] + nums2[j];
                    if (sum >= pq.top().first + pq.top().second)
                    {
                        break;
                    }
                    else
                    {
                        pq.pop();
                        pq.push(pair<int, int>(nums1[i], nums2[j]));
                    }
                }
            }
        }
        vector<vector<int>> result(k);
        for (int i = 0; i < k; i++)
        {
            pair<int, int> p = pq.top();
            pq.pop();
            vector<int> v(2);
            v[0] = p.first;
            v[1] = p.second;
            result[i] = v;
        }
        return result;
    }
};

int main()
{
    int n, m, data, k;
    vector<int> nums1, nums2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        nums1.push_back(data);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> data;
        nums2.push_back(data);
    }
    cin >> k;
    vector<vector<int>> res = Solution().kSmallestPairs(nums1, nums2, k);
    for (int i = 0; i < res.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << res[i][0] + res[i][1];
    }
    return 0;
}