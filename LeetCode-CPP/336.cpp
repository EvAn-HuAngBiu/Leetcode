#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 参考: https://blog.csdn.net/qq508618087/article/details/51443809
class Solution
{
public:
    bool isPalin(string &str)
    {
        for (int i = 0; i < str.size() / 2; i++)
            if (str[i] != str[str.size() - i - 1])
                return false;
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        unordered_map<string, int> hash;
        vector<vector<int>> result;
        for (int i = 0; i < words.size(); i++)
            hash[words[i]] = i;
        for (int i = 0; i < words.size(); i++)
        {
            reverse(words[i].begin(), words[i].end());
            int len = words[i].size();
            for (int j = 0; j <= len; j++)
            {
                string left = words[i].substr(0, j), right = words[i].substr(j);
                if (hash.count(left) && isPalin(right) && hash[left] != i)
                    result.push_back(vector<int>{hash[left], i});
                if (hash.count(right) && isPalin(left) && hash[right] != i && j > 0)
                    result.push_back(vector<int>{i, hash[right]});
            }
        }
        return result;
    }
};

int main()
{
    for (int i : Solution().manacher("ababacd"))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}