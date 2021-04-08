#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> inner;
    vector<vector<int>> graph;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        inner.assign(numCourses, 0);
        graph.assign(numCourses, vector<int>());
        for (const vector<int>& prerequisite : prerequisites) {
            int cur = prerequisite[1];
            // for (int i = 1; i < prerequisite.size(); ++i) {
                graph[cur].emplace_back(prerequisite[0]);
                ++inner[prerequisite[0]];
            // }
        }

        queue<int> available;
        for (int i = 0; i < numCourses; ++i) {
            if (inner[i] == 0) {
                available.emplace(i);
            }
        }
        vector<int> result;
        while (!available.empty()) {
            int cur = available.front();
            available.pop();
            result.emplace_back(cur);
            inner[cur] = -1;
            for (auto& c : graph[cur]) {
                --inner[c];
                if (inner[c] == 0) {
                    available.emplace(c);
                }
            }
        }
        return result.size() == numCourses ? result : vector<int>();
    }
};

int main()
{
    int numCourses;
    vector<vector<int>> v = {{1, 0}};
    vector<int> result = Solution().findOrder(2, v);
    for (auto& i : result) {
        cout << i << " ";
    }
    return 0;
}