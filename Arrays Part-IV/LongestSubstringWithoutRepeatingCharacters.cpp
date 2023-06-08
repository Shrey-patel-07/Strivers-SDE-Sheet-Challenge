#include <bits/stdc++.h>
using namespace std;

int uniqueSubstrings(string input)
{
    vector<int> mp(256, -1);
    int maxi = 0;
    int ind = -1;
    for (int i = 0; i < input.length(); i++)
    {
        if (mp[input[i]] > ind)
            ind = mp[input[i]];
        mp[input[i]] = i;
        maxi = max(maxi, i - ind);
    }
    return maxi;
    // Write your code here
}