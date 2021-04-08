#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class UF {
private:
    vector<int> father;
public:
    UF(int n) {
        int total = 4 * n * n;
        father = vector<int>(total);
        for (int i = 0; i < total; ++i) {
            father[i] = i;
        }
    }

    int find(int a) {
        while (a != father[a]) {
            a = father[a];
        }
        return a;
    }

    void union_ (int a, int b) {
        int fa = find(a);
        int fb = find(b);
        if (fa != fb) {
            father[fa] = fb;
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        UF uf(n);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                int base = 4 * (n * r + c);
                if (grid[r][c] != '/') {
                    uf.union_(base, base + 1);
                    uf.union_(base + 2, base + 3);
                }
                if (grid[r][c] != '\\') {
                    uf.union_(base, base + 3);
                    uf.union_(base + 1, base + 2);
                }

                if (r + 1 < n) {
                    uf.union_(base + 2, (base + 4 * n));
                }
                if (r > 0) {
                    uf.union_(base, (base - 4 * n) + 2);
                }
                if (c + 1 < n) {
                    uf.union_(base + 1, (base + 4) + 3);
                }
                if (c > 0) {
                    uf.union_(base + 3, (base - 4) + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 4 * n * n; ++i) {
            if (uf.find(i) == i) {
                ++ans;
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    vector<string> grid;
    string line;
    cin >> n;
    cin.get();
    for(int i = 0; i < n; i++)
    {
        getline(cin, line);
        grid.push_back(line);
    }
    int res=Solution().regionsBySlashes(grid);
    cout << res;
}