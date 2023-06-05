#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
        if (count[arr[i]] == n / 3 + 1)
            ans.push_back(arr[i]);
    }
    return ans;
}