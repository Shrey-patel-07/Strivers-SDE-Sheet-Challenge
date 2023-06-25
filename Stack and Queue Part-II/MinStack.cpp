#include <bits/stdc++.h>
using namespace std;
class minStack
{
public:
    stack<pair<int, int>> s1;
    minStack() {}
    void push(int num)
    {
        int mini;
        if (s1.empty())
            mini = num;
        else
            mini = min(num, s1.top().second);
        s1.push({num, mini});
    }
    int pop()
    {
        if (s1.empty())
            return -1;
        int x = s1.top().first;
        s1.pop();
        return x;
    }
    int top()
    {
        if (s1.empty())
            return -1;
        return s1.top().first;
    }
    int getMin()
    {
        if (s1.empty())
            return -1;
        return s1.top().second;
    }
};