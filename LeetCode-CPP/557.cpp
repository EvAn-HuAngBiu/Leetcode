#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result;
        // 利用C库函数分割，最差空间复杂度为O(n)即无空格的情况
        char* cur = strtok(const_cast<char *>(s.c_str()), " ");
        while (cur) {
            string c = string(cur);
            // 逆置
            reverse(c.begin(), c.end());
            result += c;
            cur = strtok(NULL, " ");
            if (cur) {
                result += " ";
            }
        }
        return result;
    }
};

int main()
{
    cout << Solution().reverseWords("Let's take LeetCode contest") << endl;
    return 0;
}