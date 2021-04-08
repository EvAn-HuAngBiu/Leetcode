#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int index = 0, size = strs.size();
    char cur;
    while (1) {
        for (int i = 0; i < size; i++) {
            if (index >= strs[i].size() || (i && strs[i][index] != cur)) {
                return strs[0].substr(0, index);
            } else {
                cur = strs[i][index];
            }
        }
        ++index;
    }
    return "";
}

int main()
{
    vector<string> v = {
        "flower","flow","flight"
    };
    cout << longestCommonPrefix(v) << endl;
    return 0;
}