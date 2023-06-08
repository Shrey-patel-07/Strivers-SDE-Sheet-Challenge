#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{

    if (n == 1)
        return 1;
    sort(arr.begin(), arr.end());
    int maxi = 1;
    int cur = 1;
    int prev = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == prev + 1)
            cur++;
        else if (arr[i] != prev)
            cur = 1;
        prev = arr[i];
        maxi = max(maxi, cur);
    }
    return maxi;
}