#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> &mat, vector<int> &col, int curr_idx, int curr_col, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i != curr_idx && mat[i][curr_idx] == 1 && col[i] == curr_col)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &mat, vector<int> &col, int curr_idx, int m, int n)
{
    if (curr_idx == n)
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(mat, col, curr_idx, i, n))
        {
            col[curr_idx] = i;
            if (solve(mat, col, curr_idx + 1, m, n))
                return true;
            col[curr_idx] = -1;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m)
{
    int n = mat.size();
    vector<int> col(n, -1);
    if (solve(mat, col, 0, m, n))
        return "YES";
    return "NO";
}