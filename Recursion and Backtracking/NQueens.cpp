#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &ans, int col, int n, vector<vector<int>> &board, vector<int> &lr, vector<int> &ld, vector<int> &ud)
{
    if (col == n)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (lr[row] == 0 && ld[row + col] == 0 && ud[n - 1 + col - row] == 0)
        {
            board[row][col] = 1;
            lr[row] = 1;
            ld[row + col] = 1;
            ud[n - 1 + col - row] = 1;
            solve(ans, col + 1, n, board, lr, ld, ud);
            board[row][col] = 0;
            lr[row] = 0;
            ld[row + col] = 0;
            ud[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> lr(n, 0);
    vector<int> ld(2 * n - 1, 0);
    vector<int> ud(2 * n - 1, 0);
    solve(ans, 0, n, board, lr, ld, ud);

    return ans;
}