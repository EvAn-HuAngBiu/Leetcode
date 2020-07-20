#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> result;
void calculate(const string &s, string cur, int beg, int time) {
    if (time == 4 && beg == s.size()) {
        result.push_back(cur);
        return;
    } else if (time == 4 && beg != s.size()) {
        return;
    }
    for (int j = 1; j <= 3; j++) {
        string sub = s.substr(beg, j);
        if (beg + j <= s.size() && atoi(sub.c_str()) <= 255) {
            if (sub[0] == '0' && sub.size() != 1) {
                break;
            }
            if (time == 3) {
                calculate(s, cur + s.substr(beg, j), beg + j, time + 1);
            } else {
                calculate(s, cur + s.substr(beg, j) + ".", beg + j, time + 1);
            }
        } else {
            break;
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    int size = s.size();
    if (size < 4 || size > 12) {
        return vector<string>();
    }
    calculate(s, "", 0, 0);
    return result;
}

int main() {
    string s;
    cin >> s;
    cout << restoreIpAddresses(s).size() << endl;
    return 0;
}