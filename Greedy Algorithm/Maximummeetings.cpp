#include <bits/stdc++.h>
using namespace std;
bool static sec(const vector<int> &a, vector<int> &b)
{
    if (a[0] < b[0])
        return true;
    else if (a[0] > b[0])
        return false;
    else if (a[2] < b[2])
    {
        return true;
    }
    return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{ // Write your code here.
    vector<int> ans;
    int n = start.size();
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = {end[i], start[i], i + 1};
    }
    sort(v.begin(), v.end(), sec);
    int en = v[0][0];
    ans.push_back(v[0][2]);
    for (int i = 1; i < n; i++)
    {
        if (v[i][1] > en)
        {
            en = v[i][0];
            ans.push_back(v[i][2]);
        }
    }
    return ans;
}