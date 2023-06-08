#include <bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    int mp[n + 1] = {0};
    int repeat = -1, missing = -1;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp[i] == 2)
            repeat = i;
        else if (mp[i] == 0)
            missing = i;

        if (repeat != -1 && missing != -1)
            break;
    }
    return {missing, repeat};
}
