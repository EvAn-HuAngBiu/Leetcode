#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> graph(n, vector<int>());
        vector<int> degree(n, 0);
        for (const vector<int>& edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
            ++degree[edge[0]];
            ++degree[edge[1]];
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        vector<int> result;
        while (!q.empty()) {
            result.clear();
            int size = q.size(), cur;
            for (int i = 0; i < size; i++) {
                cur = q.front();
                q.pop();
                result.emplace_back(cur);
                --degree[cur];
                for (const int& n : graph[cur]) {
                    if (--degree[n] == 1) {
                        q.push(n);
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    int n;
    vector<vector<int> > edges;
    cin>>n;
    int p1,p2;
    for(int i=0; i<n-1; i++)//边的数目为节点数目减1
    {
        cin>>p1>>p2;
        vector<int> edge;
        edge.push_back(p1);
        edge.push_back(p2);
        edges.push_back(edge);
    }
    vector<int> res=Solution().findMinHeightTrees(n, edges);
    sort(res.begin(), res.end());
    for(int i=0; i<res.size(); i++)
    cout<<res[i]<<" ";
}