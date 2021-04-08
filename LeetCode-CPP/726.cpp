#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

map<string, int> calculate(const string& formula, int begin, int end) {
    map<string, int> result;
    for (int i = begin; i < end; i++) {
        if (isupper(formula[i])) {
            string cur;
            cur += formula[i];
            int repeat = 1;
            if (islower(formula[i + 1])) {
                cur += formula[++i];
            }
            if (isdigit(formula[i + 1])) {
                repeat = formula[++i] - '0';
            }
            ++result[cur];
        } else if (formula[i] == '(') {
            int end = i + 1;
            while (formula[i] != ')') {
                ++end;
            }
            map<string, int> m = calculate(formula, i + 1, end);
            for (auto& it : m) {
                result[it.first] += it.second;
            }
            i = end + 1;
        }
    }
    return result;
}

string countOfAtoms(string formula) {
    map<string, int> m = calculate(formula, 0, formula.size());
    return string();
}

int main()
{
    return 0;
}