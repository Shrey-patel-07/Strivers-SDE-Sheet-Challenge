#include <bits/stdc++.h>
using namespace std;

void f(string &s, int index, vector<string> &ans)
{
    if (index == s.length())
    {
        ans.push_back(s);
        return;
    }

    for (int i = index; i < s.length(); i++)
    {
        swap(s[i], s[index]);
        f(s, index + 1, ans);
        swap(s[index], s[i]);
    }
}

vector<string> findPermutations(string &s)
{
    // Write your code here.
    vector<string> ans;
    f(s, 0, ans);
    return ans;
}