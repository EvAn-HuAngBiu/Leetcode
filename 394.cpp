#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool isnumber(char i)
{
    return i >= '0' && i <= '9';
}

bool isalpha(char i)
{
    return (i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z');
}

void handleEnd(stack<int> &time, stack<char> &code)
{
    string temp;
    int cnt = time.top();
    time.pop();
    while (code.top() != '[')
    {
        temp += code.top();
        code.pop();
    }
    code.pop();
    reverse(temp.begin(), temp.end());
    string cur;
    for (int j = 0; j < cnt; j++)
    {
        cur += temp;
    }
    for (int j = 0; j < cur.size(); j++)
    {
        code.push(cur[j]);
    }
}

string decodeString(string s)
{
    stack<int> time;
    stack<char> code;
    for (char i : s)
    {
        if (isnumber(i))
        {
            time.push(i - '0');
        }
        else if (isalpha(i) || i == '[')
        {
            code.push(i);
        }
        else
        {
            handleEnd(time, code);
        }
    }
    if (!time.empty())
    {
        handleEnd(time, code);
    }
    string result;
    while (!code.empty())
    {
        result += code.top();
        code.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string s;
    cin >> s;
    cout << decodeString(s) << endl;
    return 0;
}