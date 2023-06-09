#include <bits/stdc++.h>
using namespace std;

void f(vector<int> arr, int ind, int k, vector<vector<int>> &ans, vector<int> &row)
{
    if (ind == arr.size())
    {
        if (k == 0)
            ans.push_back(row);
        return;
    }
    row.push_back(arr[ind]);
    f(arr, ind + 1, k - arr[ind], ans, row);
    row.pop_back();
    f(arr, ind + 1, k, ans, row);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> row;
    f(arr, 0, k, ans, row);
    return ans;
}