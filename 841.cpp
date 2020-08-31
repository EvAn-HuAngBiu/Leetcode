#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<bool> visited;
public:
    void dfs(const vector<vector<int>>& g, int cur) {
        visited[cur] = true;
        const vector<int>& anc = g[cur];
        int size = anc.size();
        for (int i = 0; i < size; ++i) {
            if (!visited[anc[i]]) {
                dfs(g, anc[i]);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        if (!size) {
            return true;
        }
        visited = vector<bool>(size, false);
        dfs(rooms, 0);
        for (auto b : visited) {
            if (!b) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<int>> g = {
        {1, 3},
        {3, 0, 1},
        {2},
        {0}
    };
    cout << boolalpha << Solution().canVisitAllRooms(g) << endl;
    return 0;
}