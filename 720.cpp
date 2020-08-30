#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Tire {
public:
    unordered_map<char, Tire*> next;
};

class Solution {
private:
    int max_len = 0;
    string result;
    Tire* root = new Tire();
public:
    void insert(string& word) {
        Tire* cur = root;
        int size = word.size();
        for (int i = 0; i < size - 1; ++i) {
            if (cur->next.find(word[i]) == cur->next.end()) {
                return;
            }
            cur = cur->next[word[i]];
        }
        cur->next[word[size - 1]] = new Tire();
        if (size > max_len || (size == max_len && word < result)) {
            max_len = size;
            result = word;
        }
    }

    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        for (auto& word : words) {
            insert(word);
        }
        return result;
    }
};

int main()
{
    vector<string> v = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << Solution().longestWord(v) << endl;
    return 0;
}