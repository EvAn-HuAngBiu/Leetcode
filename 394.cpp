#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

int beg = 0;
string loop(const string& s) {
    int times = 0;
    int size = s.size();
    if (beg >= size) {
        return "";
    }
    while (isnumber(s[beg])) {
        times = times * 10 + s[beg] - '0';
        beg++;
    }
    string result;
    if (times == 0) {
        while (beg < size && isalpha(s[beg])) {
            result += s[beg++];
        }
        return result;
    } else {
        ++beg;
        while (beg < size && isalpha(s[beg])) {
            result += s[beg++];
        }
        while (s[beg] != ']') {
            result += loop(s);
        }
        ++beg;
        string temp(result);
        for (int i = 1; i < times; i++) {
            result += temp;
        }
        return result;
    }
}

string decodeString(string s) {
    string result;
    while (beg < s.size()) {
        result += loop(s);
    }
    return result;
}

int main()
{
    string s = "2[2[y]pq]";
    cin >> s;
    cout << decodeString(s) << endl;
    return 0;
}