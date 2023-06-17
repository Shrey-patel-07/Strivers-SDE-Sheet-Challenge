#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, int n, vector<vector<int>> &maze, vector<vector<int>> &visited, vector<vector<int>> &ans)
{
    if (i < 0 || j < 0 || i >= n || j >= n || visited[i][j] == 1 || maze[i][j] == 0)
    {
        return;
    }
    if (i == n - 1 && j == n - 1)
    {
        vector<int> temp;
        visited[i][j] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp.push_back(visited[i][j]);
            }
        }
        visited[i][j] = 0;
        ans.push_back(temp);
        return;
    }
    visited[i][j] = 1;
    solve(i, j - 1, n, maze, visited, ans);
    solve(i, j + 1, n, maze, visited, ans);
    solve(i - 1, j, n, maze, visited, ans);
    solve(i + 1, j, n, maze, visited, ans);
    visited[i][j] = 0;
}
vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    if (maze[0][0] == 1)
    {
        solve(0, 0, n, maze, visited, ans);
    }
    return ans;
}