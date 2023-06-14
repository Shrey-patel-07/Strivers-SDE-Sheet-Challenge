#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    return a[1] > b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(), jobs.end(), comp);
    int maxi = -1, profit = 0;
    for (int i = 0; i < jobs.size(); i++)
    {
        maxi = max(maxi, jobs[i][0]);
    }
    vector<int> temp(maxi + 1, -1);
    for (int i = 0; i < jobs.size(); i++)
    {
        int d = jobs[i][0];
        for (int j = d; j > 0; j--)
        {
            if (temp[j] == -1)
            {
                temp[j] = jobs[i][1];
                break;
            }
        }
    }
    for (int i = 1; i <= maxi; i++)
    {
        if (temp[i] != -1)
        {
            profit += temp[i];
        }
    }
    return profit;
}
