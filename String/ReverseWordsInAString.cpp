#include <bits/stdc++.h>
using namespace std;
string reverseString(string &str)
{
    // Write your code here.
    stack<string> s;
    string temp = "";
    for (char c : str)
    {
        if (c == ' ')
        {
            if (temp != "")
            {
                s.push(temp);
                temp = "";
            }
        }
        else
        {
            temp += c;
        }
    }
    if (temp != "")
        s.push(temp);
    string ans;
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
        if (!s.empty())
            ans += " ";
    }
    return ans;
}