#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        for (auto& a : answers) {
            ++m[a];
        }
        int total = answers.size();
        for (auto& p : m) {
            if (p.second % (p.first + 1)) {
                total += p.first + 1 - p.second % (p.first + 1);
            }
        }
        return total;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << Solution().numRabbits(v) << endl;
    return 0;
}