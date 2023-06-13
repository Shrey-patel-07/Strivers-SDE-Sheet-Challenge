#include <bits/stdc++.h>
using namespace std;
long getTrappedWater(long *arr, int n)
{
    // Write your code here.
    long left = 0, right = n - 1;
    long leftmax = 0, rightmax = 0;
    long totalwater = 0;
    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {
            if (arr[left] >= leftmax)
                leftmax = arr[left];
            else
                totalwater += leftmax - arr[left];
            left++;
        }
        else
        {
            if (arr[right] >= rightmax)
                rightmax = arr[right];
            else
                totalwater += rightmax - arr[right];
            right--;
        }
    }
    return totalwater;
}