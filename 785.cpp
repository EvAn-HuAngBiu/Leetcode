#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> mark;
bool dfs(const vector<vector<int>>& graph, int cur, int color) {
    for (int i = 0; i < graph[cur].size(); i++) {
        if (!mark[graph[cur][i]]) {
            mark[graph[cur][i]] = color;
            if (!dfs(graph, graph[cur][i], color == 1 ? 2 : 1)) {
                return false;
            }
        } else if (mark[graph[cur][i]] != color) {
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    mark = vector<int>(graph.size(), 0);
    bool flag = true;
    for (int i = 0; i < graph.size(); i++) {
        if (!mark[i]) {
            mark[i] = 1;
            flag = flag && dfs(graph, i, 1);
        }
    }
    return flag;
}

int main()
{
    vector<vector<int>> v = {{1,3}, {0,2}, {1,3}, {0,2}};
    cout << boolalpha << isBipartite(v) << endl;
    return 0;
}