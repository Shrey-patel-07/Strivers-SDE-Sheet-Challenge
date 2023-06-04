#include <bits/stdc++.h>
using namespace std;
long long maxSubarraySum(int arr[], int n)
{
    long long int maxi = INT_MIN;
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
            sum = 0;
        maxi = max(maxi, sum);
    }
    return maxi;
}