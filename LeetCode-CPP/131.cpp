#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> dp;
vector<vector<string>> result;
void dfs(const string& s, vector<string>& v, int beg) {
    int size = s.size();
    if (beg == size) {
        result.push_back(v);
        return;
    }
    for (int i = 1; beg + i <= size; i++) {
        if (dp[beg][beg + i - 1]) {
            v.push_back(s.substr(beg, i));
            dfs(s, v, beg + i);
            v.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    int size = s.size();
    dp = vector<vector<int>>(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        dp[i][i] = 1;
        if (i + 1 < size && s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
        }
    }
    int j;
    for (int l = 3; l <= size; l++) {
        for (int i = 0; l + i - 1 < size; i++) {
            j = l + i - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= size; i++) {
        if (dp[0][i - 1]) {
            vector<string> v;
            v.push_back(s.substr(0, i));
            dfs(s, v, i);
        }
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    const vector<vector<string>> v = partition(s);
    cout << v.size() << endl;
    return 0;
}