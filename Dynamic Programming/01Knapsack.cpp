#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int i = weights[0]; i <= w; i++)
    {
        dp[0][i] = values[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int dog = 0; dog <= w; dog++)
        {
            int nottaken = dp[i - 1][dog];
            int taken = INT_MIN;
            if (weights[i] <= dog)
            {
                taken = values[i] + dp[i - 1][dog - weights[i]];
            }
            dp[i][dog] = max(nottaken, taken);
        }
    }
    return dp[n - 1][w];
    // Write your code here
}