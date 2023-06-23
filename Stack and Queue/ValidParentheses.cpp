#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<int> s;
    for (auto chr : expression)
    {
        if (chr == '{' || chr == '[' || chr == '(')
            s.push(chr);
        else
        {
            if (s.empty())
                return false;
            char temp = s.top();
            s.pop();
            if ((chr == ')' && temp == '(') || (chr == '}' && temp == '{') ||
                (chr == ']' && temp == '['))
                continue;
            else
                return false;
        }
    }
    return s.empty();
}