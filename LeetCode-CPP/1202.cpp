#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> father;
public:
    int find(int a) {
        int s = a, t;
        while (father[a] != a) {
            a = father[a];
        }
        while (s != a) {
            t = father[s];
            father[s] = a;
            s = t;
        }
        return a;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int size = s.size();
        father.assign(size, 0);
        for (int i = 0; i < size; ++i) {
            father[i] = i;
        }
        for (auto& pair : pairs) {
            father[find(pair[0])] = find(pair[1]);
        }
        vector<vector<char>> v(size);
        for (int i = 0; i < size; ++i) {
            v[find(i)].emplace_back(s[i]);
        }
        for (int i = 0; i < size; ++i) {
            sort(v[i].rbegin(), v[i].rend());
        }
        string result;
        for (int i = 0; i < size; ++i) {
            result += v[father[i]].back();
            v[father[i]].pop_back();
        }
        return result;
    }
};

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> v[i][0] >> v[i][1];
    }
    cout << Solution().smallestStringWithSwaps(s, v) << endl;
    return 0;
}