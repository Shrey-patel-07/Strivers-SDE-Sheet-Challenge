#include <bits/stdc++.h>
using namespace std;

int f(int ind, int prev, vector<int> &rack, vector<vector<int>> &dp)
{
    if (ind == rack.size())
    {
        return 0;
    }
    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];
    int notTake = f(ind + 1, prev, rack, dp);
    int take = INT_MIN;
    if (prev == -1 || rack[prev] < rack[ind])
    {
        take = rack[ind] + f(ind + 1, ind, rack, dp);
    }
    return dp[ind][prev + 1] = max(take, notTake);
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, rack, dp);
}