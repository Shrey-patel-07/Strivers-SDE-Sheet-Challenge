#include <bits/stdc++.h>
using namespace std;
void f(int ind, vector<int> &num, vector<int> &ans, int n, int sum)
{
    if (ind == n)
    {
        ans.push_back(sum);
        return;
    }
    f(ind + 1, num, ans, n, sum + num[ind]);
    f(ind + 1, num, ans, n, sum);
}

vector<int> subsetSum(vector<int> &num)
{
    int n = num.size();
    vector<int> ans;
    f(0, num, ans, n, 0);
    sort(ans.begin(), ans.end());
    return ans;
}