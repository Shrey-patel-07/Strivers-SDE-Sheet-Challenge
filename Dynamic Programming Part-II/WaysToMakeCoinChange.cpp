#include <bits/stdc++.h>
using namespace std;

long f(int ind, int tar, int *destinations, vector<vector<long>> &dp)
{
    if (ind == 0)
        return tar % destinations[0] == 0;
    if (dp[ind][tar] != -1)
        return dp[ind][tar];
    long nottake = f(ind - 1, tar, destinations, dp);
    long take = 0;
    if (tar >= destinations[ind])
        take = f(ind, tar - destinations[ind], destinations, dp);
    return dp[ind][tar] = take + nottake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return f(n - 1, value, denominations, dp);
}