#include <bits/stdc++.h>
using namespace std;
void sortStack(stack<int> &sta)
{
    // Write your code here
    stack<int> s;
    while (!sta.empty())
    {
        int cre = sta.top();
        sta.pop();

        while (!s.empty() && cre > s.top())
        {
            sta.push(s.top());
            s.pop();
        }
        s.push(cre);
    }
    while (!s.empty())
    {
        sta.push(s.top());
        s.pop();
    }
}