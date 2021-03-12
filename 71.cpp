#include <iostream>
#include <stack>
#include <string>
using namespace std;

void handleEnd(stack<string> &s, string cur)
{
    if (cur == "..")
    {
        if (!s.empty())
        {
            s.pop();
        }
    }
    else if (cur != ".")
    {
        s.push(cur);
    }
}

string simplifyPath(string path)
{
    stack<string> s;
    string temp;
    bool pre = true;
    for (int i = 1; i < path.size(); i++)
    {
        if (path[i] != '/')
        {
            temp += path[i];
            pre = false;
        }
        else if (path[i] == '/')
        {
            if (!pre)
            {
                pre = true;
                handleEnd(s, temp);
            }
            temp = "";
        }
    }
    if (temp != "") {
        handleEnd(s, temp);
    }
    stack<string> rev;
    while (!s.empty())
    {
        rev.push(s.top());
        s.pop();
    }
    string result = "/";
    while (!rev.empty())
    {
        result += rev.top() + '/';
        rev.pop();
    }
    return result.size() == 1 ? "/" : result.substr(0, result.size() - 1);
}

int main()
{
    string s;
    cin >> s;
    cout << simplifyPath(s) << endl;
    return 0;
}