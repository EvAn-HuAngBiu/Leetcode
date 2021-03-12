#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> inner;
    vector<vector<int>> graph;

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        inner.assign(numCourses, 0);
        graph.assign(numCourses, vector<int>());
        for (const vector<int> &prerequisite : prerequisites)
        {
            int cur = prerequisite[0];
            for (int i = 1; i < prerequisite.size(); ++i)
            {
                graph[cur].emplace_back(prerequisite[i]);
                ++inner[prerequisite[i]];
            }
        }

        queue<int> available;
        for (int i = 0; i < numCourses; ++i)
        {
            if (inner[i] == 0)
            {
                available.emplace(i);
            }
        }
        int done = 0;
        while (!available.empty())
        {
            int cur = available.front();
            available.pop();
            ++done;
            inner[cur] = -1;
            for (auto &c : graph[cur])
            {
                --inner[c];
                if (inner[c] == 0)
                {
                    available.emplace(c);
                }
            }
        }
        return done == numCourses;
    }
};

int main()
{
    vector<vector<int>> prerequisites;
    int numCourses, m;
    cin >> numCourses >> m;
    int c1, c2;
    int ch;
    for (int i = 0; i < m; i++)
    {
        vector<int> aPrerequisite;
        cin >> c1 >> c2;
        aPrerequisite.push_back(c1);
        aPrerequisite.push_back(c2);
        prerequisites.push_back(aPrerequisite);
    }

    bool res = Solution().canFinish(numCourses, prerequisites);
    cout << boolalpha << res << endl;
    return 0;
}