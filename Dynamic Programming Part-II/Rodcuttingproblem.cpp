
#include <bits/stdc++.h>
using namespace std;

int f(int ind, int len, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
        return len * price[ind];
    if (dp[ind][len] != -1)
        return dp[ind][len];
    int nottake = f(ind - 1, len, price, dp);
    int take = 0;
    if (len >= ind + 1)
        take = price[ind] + f(ind, len - ind - 1, price, dp);
    return dp[ind][len] = max(take, nottake);
}

int cutRod(vector<int> &price, int len)
{
    // Write your code here.
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(len + 1, -1));
    return f(n - 1, len, price, dp);
}
