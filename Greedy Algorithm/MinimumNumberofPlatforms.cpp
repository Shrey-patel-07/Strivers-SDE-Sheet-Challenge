#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    sort(at, at + n);
    sort(dt, dt + n);

    int ans = 1;
    int count = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (at[i] <= dt[j])
        {
            count++, i++;
        }
        else
            count--, j++;
        ans = max(ans, count);
    }
    return ans;
}