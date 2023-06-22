#include <bits/stdc++.h>
using namespace std;
bool wordBreak(vector<string> &arr, int n, string &target)
{
    // Write your code here.
    vector<bool> dp(target.size() + 1, 0);
    dp[0] = true;
    unordered_set<string> set(arr.begin(), arr.end());
    for (int i = 1; i <= target.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && set.count(target.substr(j, i - j)))
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[target.size()];
}