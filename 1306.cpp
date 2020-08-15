#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0) {
            return true;
        }
        int size = arr.size();
        set<int> index;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int cur = q.front();
            if (arr[cur] == 0) {
                return true;
            }
            q.pop();
            index.insert(cur);
            int add = cur + arr[cur], sub = cur - arr[cur];
            if (add < size && index.find(add) == index.end()) {
                q.push(add);
            }
            if (sub >= 0 && index.find(sub) == index.end()) {
                q.push(sub);
            }
        }
        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int start;
    cin >> start;
    cout << boolalpha << Solution().canReach(v, start) << endl;
    return 0;
}