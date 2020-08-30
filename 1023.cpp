#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static bool lower(char c) {
        return c >= 'a' && c <= 'z';
    }

    static bool upper(char c) {
        return c >= 'A' && c <= 'Z';
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int size = queries.size();
        vector<bool> result(size, false);
        for (int i = 0; i < size; ++i) {
            string& cur = queries[i];
            int p = 0, ps = pattern.size();
            int q = 0, qs = cur.size();
            bool flag = true;
            while (q < qs) {
                // 处理模式串到达结束
                if (p == ps && upper(cur[q])) {
                    flag = false;
                    break;
                }
                if (p == ps && lower(cur[q])) {
                    ++q;
                    continue;
                }
                // 模式串和匹配串当前字符匹配
                if (pattern[p] == cur[q]) {
                    ++p;
                    ++q;
                    continue;
                } else if (lower(cur[q])) {
                    // 不匹配但是匹配串为小写，跳过
                    ++q;
                    continue;
                } else {
                    // 不匹配但是匹配串为大写，退出
                    flag = false;
                    break;
                }
            }
            result[i] = flag && (q == qs) && (p == ps);
        }
        return result;
    }
};

int main()
{
    string pattern;
    cin >> pattern;
    int n;
    cin >> n;
    vector<string> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i];
    }
    vector<bool> result = Solution().camelMatch(queries, pattern);
    for (int i = 0; i < result.size(); ++i) {
        if (i) {
            cout << " ";
        }
        cout << boolalpha << result[i];
    }
    return 0;
}