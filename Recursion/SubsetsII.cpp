#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &arr, int ind, vector<int> &row, vector<vector<int>> &ans)
{
    ans.push_back(row);
    for (int i = ind; i < arr.size(); i++)
    {
        if (i != ind && arr[i] == arr[i - 1])
            continue;
        row.push_back(arr[i]);
        f(arr, i + 1, row, ans);
        row.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> row;
    f(arr, 0, row, ans);
    return ans;
    // Write your code here.
}