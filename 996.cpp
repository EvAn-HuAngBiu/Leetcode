#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <set>
using namespace std;

map<int, vector<int>> graph;
// vector<vector<int>> graph;
int result = 0;
void dfs(const vector<int>& a, vector<bool>& visit, int remain, int cur) {
    if (remain == 0) {
        ++result;
        return;
    }
    set<int> dup;
    for (int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i];
        if (!visit[next] && dup.find(a[next]) == dup.end()) {
            visit[next] = true;
            dfs(a, visit, remain - 1, next);
            visit[next] = false;
            dup.insert(a[next]);
        }
    }
}

int numSquarefulPerms(vector<int>& A) {
    int size = A.size(), sum, sq;
    map<int, bool> beginFlag;
    for (int i = 0; i < size; i++) {
        beginFlag[A[i]] = true;
        for (int j = i + 1; j < size; j++) {
            sum = A[i] + A[j];
            sq = sqrt(sum);
            if (sq * sq == sum) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (beginFlag[A[i]]) {
            beginFlag[A[i]] = false;
            vector<bool> visit(size, false);
            visit[i] = true;
            dfs(A, visit, size - 1, i);
        }
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
    cout << numSquarefulPerms(v) << endl;
    return 0;
}