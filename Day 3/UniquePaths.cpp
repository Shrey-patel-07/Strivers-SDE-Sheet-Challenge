#include <bits/stdc++.h>
using namespace std;

int f(int m, int n, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
        return 1;
    if (n < 0 || m < 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];
    int left = f(m, n - 1, dp);
    int up = f(m - 1, n, dp);
    return dp[m][n] = left + up;
}
int uniquePaths(int m, int n)
{
    // Write your code here.
    //     vector<vector<int>> dp(m,vector<int>(n,-1));
    //     return f(m-1,n-1,dp);
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}