#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    struct Step {
        string a;
        int step;
        Step() {}
        Step(string a, int step) : a(a), step(step) {}
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

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int size = wordList.size();
        if (!size || beginWord == endWord || 
                find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        vector<bool> visited(size, false);
        queue<Step> q;
        q.push(Step(beginWord, 1));
        while (!q.empty()) {
            Step cur = q.front();
            q.pop();
            if (cur.a == endWord) {
                return cur.step;
            }
            for (int i = 0; i < wordList.size(); ++i) {
                if (!visited[i] && change(cur.a, wordList[i])) {
                    visited[i] = true;
                    q.push(Step(wordList[i], cur.step + 1));
                }
            }
        }
        return 0;
    }
};

int main()
{
    return 0;
}