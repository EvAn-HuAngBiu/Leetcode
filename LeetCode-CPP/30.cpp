#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool cmp(const unordered_map<string, int>& m1, unordered_map<string, int>& m2) {
        for (auto& it : m1) {
            if (m2.find(it.first) == m2.end() || m2[it.first] != it.second) {
                return false;
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> pattern, cur;
        int wsize = words.size(), ssize = s.size();
        if (!wsize || !ssize) {
            return {};
        }
        int each = words[0].size();
        for (auto& word : words) {
            ++pattern[word];
        }
        vector<int> result;
        for (int i = 0; i + wsize * each <= ssize; ++i) {
            cur.clear();
            for (int j = i; j < i + wsize * each; j += each) {
                ++cur[s.substr(j, each)];
            }
            if (cmp(pattern, cur)) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};

int main()
{
    string s,str;
    vector<string> words;
    int n;
    cin>>s;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>str;
        words.push_back(str);
    }
    vector<int> res=Solution().findSubstring(s, words);
    if (res.size()> 0)
        for(int i=0; i<res.size(); i++)
        {
            if (i> 0)
                cout<<" ";
            cout<<res[i];
        }
    else
        cout<<-1;

    return 0;
}
