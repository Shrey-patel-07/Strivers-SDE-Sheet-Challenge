#include <bits/stdc++.h>
using namespace std;
struct pr
{
    int s;
    int e;
    int position;
};

bool comp(struct pr a, struct pr b)
{
    if (a.e < b.e)
        return true;
    else if (a.e > b.e)
        return false;
    else if (a.position < b.position)
        return true;
    return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish)
{
    // Write your code here.
    int n = start.size();
    struct pr meet[n];
    for (int i = 0; i < n; i++)
    {
        meet[i].s = start[i];
        meet[i].e = finish[i];
        meet[i].position = i + 1;
    }
    sort(meet, meet + n, comp);

    int limit = -1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (meet[i].s > limit - 1)
        {
            ans++;
            limit = meet[i].e;
        }
    }
    return ans;
}