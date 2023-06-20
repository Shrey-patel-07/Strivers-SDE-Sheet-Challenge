#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid)
{
    if (i == 0 && j == 0)
        return grid[i][j];
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = grid[i][j] + f(i - 1, j, dp, grid);
    int left = grid[i][j] + f(i, j - 1, dp, grid);
    return dp[i][j] = min(left, up);
}

int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, dp, grid);
}

/**
 int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
       vector<vector<int>> dp(n,vector<int>(m,0));
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(i==0 &&j==0) dp[i][j]=grid[i][j];
               else
               {
               int up=grid[i][j];
               if(i>0) up +=dp[i-1][j];
               else{up=1e9;}
               int left=grid[i][j];               
               if(j>0) left+=dp[i][j-1];
               else{left=1e9;}
               dp[i][j]=min(left,up);
               }
           }
       }
    return dp[n-1][m-1];
}
 */