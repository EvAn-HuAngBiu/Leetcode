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

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        inner.assign(numCourses, 0);
        graph.assign(numCourses, vector<int>());
        for (const vector<int>& prerequisite : prerequisites) {
            int cur = prerequisite[0];
            for (int i = 1; i < prerequisite.size(); ++i) {
                graph[cur].emplace_back(prerequisite[i]);
                ++inner[prerequisite[i]];
            }
        }

        queue<int> available;
        for (int i = 0; i < numCourses; ++i) {
            if (inner[i] == 0) {
                available.emplace(i);
            }
        }
        int done = 0;
        while (!available.empty()) {
            int cur = available.front();
            available.pop();
            ++done;
            inner[cur] = -1;
            for (auto& c : graph[cur]) {
                --inner[c];
                if (inner[c] == 0) {
                    available.emplace(c);
                }
            }
        }
        return done == numCourses;
    }
};

int main()
{
    int numCourses;
    vector<vector<int>> v = {{1, 0}, {0, 1}};
    cout << boolalpha << Solution().canFinish(2, v) << endl;
    return 0;
}