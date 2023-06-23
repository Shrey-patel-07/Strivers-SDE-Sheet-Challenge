#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreater(vector<int> &arr, int n)
{
    // Write your code here
    vector<int> ngi(n, -1);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i % n])
        {
            s.pop();
        }
        if (!s.empty())
            ngi[i] = s.top();
        s.push(arr[i % n]);
    }
    return ngi;
}