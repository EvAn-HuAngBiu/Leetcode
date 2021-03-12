#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class UF {
private:
    int father[20001];
public:
    UF() {
        for (int i = 0; i < 20001; ++i) {
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
    int removeStones(vector<vector<int>>& stones) {
        UF uf;
        for (auto& stone : stones) {
            uf.union_(stone[0], stone[1] + 10000);
        }
        unordered_set<int> us;
        for (auto& stone: stones) {
            us.insert(uf.find(stone[0]));
        }
        return stones.size() - us.size();
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> stones(n);
    for (int i = 0; i < n; ++i) {
        vector<int> stone(2);
        cin >> stone[0] >> stone[1];
        stones[i] = stone;
    }
    cout << Solution().removeStones(stones) << endl;
    return 0;
}