#include <bits/stdc++.h>
using namespace std;
bool isPossible(int n, int m, vector<int> &arr, long long int mid)
{
    int dayCount = 1;
    long long int timeCount = 0;

    for (int i = 0; i < m; i++)
    {
        if (timeCount + arr[i] <= mid)
        {
            timeCount += arr[i];
        }
        else
        {
            dayCount++;
            if (dayCount > n || arr[i] > mid)
            {
                return false;
            }
            else
            {
                timeCount = arr[i];
            }
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Write your code here.
    long long int low = 0;
    long long int sum = accumulate(time.begin(), time.end(), 0LL);
    long long int high = sum;
    long long int ans = -1;

    while (low <= high)
    {
        long long int mid = low + (high - low) / 2;
        if (isPossible(n, m, time, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}