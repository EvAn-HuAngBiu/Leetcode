#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        int index = s.find_last_of(' ');
        return s.substr(index + 1).size();
    }
};

int main()
{
    cout << Solution().lengthOfLastWord(" a ") << endl;
    return 0;
}