#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

struct cmp {
    bool operator ()(const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> m;
    for (int num : nums) {
        if (m.find(num) != m.end()) {
            ++m[num];
        } else {
            m[num] = 1;
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
    for (pair<int, int> p : m) {
        pq.push(p);
    }
    vector<int> result(k);
    for (int i = 0; i < k; i++) {
        result[i] = pq.top().first;
        pq.pop();
    }
    return result;
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
    vector<int> result = topKFrequent(v, k);
    for (int i = 0; i < k - 1; i++) {
        cout << result[i] << " ";
    }
    cout << result[k - 1] << endl;
    return 0;
}