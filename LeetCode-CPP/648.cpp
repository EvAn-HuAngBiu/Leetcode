#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;

class Tire {
public:
    bool end;
    unordered_map<char, Tire*> next;
};

class Solution {
private:
    Tire* root = new Tire();
public:
    void insert(string& word) {
        Tire* cur = root;
        for (char c : word) {
            if (cur->next.find(c) == cur->next.end()) {
                cur->next[c] = new Tire();
            }
            cur = cur->next[c];
        }
        cur->end = true;
    }

    string find(string&& word) {
        Tire* cur = root;
        int i;
        for (i = 0; i < word.size(); ++i) {
            if (cur->next.find(word[i]) == cur->next.end()) {
                return word;
            }
            cur = cur->next[word[i]];
            if (cur->end) {
                return word.substr(0, i + 1);
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for (auto& dic : dictionary) {
            insert(dic);
        }
        string result;
        char* cur = strtok(const_cast<char*>(sentence.c_str()), " ");
        while (cur) {
            result += find(string(cur)) + " ";
            cur = strtok(NULL, " ");
        }
        return result.substr(0, result.size() - 1);
    }
};

int main()
{
    int n;
    vector<string> dict;
    string sentence,word;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>word;
        dict.push_back(word);
    }
    cin.get();
    getline(cin, sentence);
    string res=Solution().replaceWords(dict, sentence);
    cout<<res;
}