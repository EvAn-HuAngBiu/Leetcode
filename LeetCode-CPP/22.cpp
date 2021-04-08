#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> result;
    void generate(string cur, int n, int left) {
        if (!n) {
            result.emplace_back(cur);
            return;
        }
        if (left < n) {
            generate(cur + "(", n, left + 1);
        }
        if (left) {
            generate(cur + ")", n - 1, left - 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        generate("(", n, 1);
        return result;
    }
};

int main()
{
    for (const string& s : Solution().generateParenthesis(3)) {
        cout << s << endl;
    }
    return 0;
}