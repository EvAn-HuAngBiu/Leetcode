#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    struct Step {
        vector<string> pre;
        Step() {}
        Step(string a) {
            pre.emplace_back(a);
        }
        Step(vector<string>& pre, string a) {
            this->pre = vector<string>(pre);
            this->pre.emplace_back(a);
        }
    };

    bool change(const string& a, const string& b) {
        bool dif = false;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                if (!dif) {
                    dif  = true;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int size = wordList.size();
        if (!size || find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return {};
        } else if (beginWord == endWord) {
            return {{beginWord}};
        }
        vector<vector<string>> result;
        queue<Step> q;
        Step beg(beginWord);
        q.push(beg);
        while (!q.empty()) {
            Step cur = q.front();
            q.pop();
            if (cur.pre.back() == endWord) {
                if (result.empty() || result[0].size() == cur.pre.size()) {
                    result.emplace_back(cur.pre);
                } else if (result[0].size() > cur.pre.size()) {
                    result.clear();
                    result.emplace_back(cur.pre);
                }
                continue;
            }
            if (cur.pre.size() >= size) {
                continue;
            }
            for (int i = 0; i < wordList.size(); ++i) {
                if (change(cur.pre.back(), wordList[i])) {
                    q.push(Step(cur.pre, wordList[i]));
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<string> word_list = {"ted","tex","red","tax","tad","den","rex","pee"};
    auto vv = Solution().findLadders("red", "tax", word_list);
    for (auto& v : vv) {
        for (auto& s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}