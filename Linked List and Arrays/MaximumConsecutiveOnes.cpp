#include <bits/stdc++.h>
using namespace std;

int longestSubSeg(vector<int> &arr, int n, int k)
{
    // Write your code here.
    int maxi = 0;
    int zero = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zero++;
        }
        while (zero > k)
        {
            if (arr[j] == 0)
            {
                zero--;
            }
            j++;
        }
        maxi = max(maxi, i - j + 1);
    }
    return maxi;
}
