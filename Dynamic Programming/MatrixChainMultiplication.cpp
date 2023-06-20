#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int ans = f(i, k, arr, dp) + f(k + 1, j, arr, dp) + arr[i - 1] * arr[k] * arr[j];
        mini = min(mini, ans);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    int i = 1;
    int j = N - 1;
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return f(i, j, arr, dp);
}

/**    Memoiation
int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int> (n, 0));

    for(int i=n-1;i>=1;i--)
    {
        for(int j=i+1;j<=n-1;j++)
        {
              int mini = 1e9;
                for(int k=i;k <= j-1; k++)
                {
                    int step = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini, step);
                }
                dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}
 */