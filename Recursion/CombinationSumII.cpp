
#include <bits/stdc++.h>

using namespace std;
void f(vector<int> &arr, int ind, int target, vector<int> &row, vector<vector<int>> &ans)
{
    //   if (ind == arr.size()) {
    if (target == 0)
    {
        ans.push_back(row);
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        if (arr[i] > target)
            break;
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        row.push_back(arr[i]);
        f(arr, i + 1, target - arr[i], row, ans);
        row.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> row;
    sort(arr.begin(), arr.end());
    f(arr, 0, target, row, ans);
    return ans;
}
