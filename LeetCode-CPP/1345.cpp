#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> map;
public:
    int minJumps(vector<int>& arr) {
        int size = arr.size();
        if (!size || size == 1) {
            return 0;
        }
        for (int i = 0; i < size; ++i) {
            map[arr[i]].push_back(i);
        }
        vector<int> dis(size, INT_MAX);
        vector<bool> visited(size, false);
        queue<int> q;
        dis[0] = 0;
        visited[0] = true;
        q.push(0);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur - 1 >= 0 && !visited[cur - 1] && map.find(arr[cur - 1]) != map.end()) {
                visited[cur - 1] = true;
                dis[cur - 1] = min(dis[cur - 1], dis[cur] + 1);
                q.push(cur - 1);
            }

            if (cur + 1 < size && !visited[cur + 1] && map.find(arr[cur + 1]) != map.end()) {
                visited[cur + 1] = true;
                dis[cur + 1] = min(dis[cur + 1], dis[cur] + 1);
                q.push(cur + 1);
            }

            if (map.find(arr[cur]) != map.end()) {
                for (auto& index : map[arr[cur]]) {
                    if (!visited[index]) {
                        visited[index] = true;
                        dis[index] = min(dis[index], dis[cur] + 1);
                        q.push(index);
                    }
                }
                map.erase(arr[cur]);
            }
        }
        return dis[size - 1];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << Solution().minJumps(arr) << endl;
    return 0;
}