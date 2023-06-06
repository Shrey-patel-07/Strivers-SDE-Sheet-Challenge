#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                int mini = min(arr[i], arr[j]);
                int maxi = max(arr[i], arr[j]);
                ans.push_back({mini, maxi});
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}