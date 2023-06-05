#include <bits/stdc++.h>
using namespace std;
vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    int left = m - 1;
    int right = n - 1;
    int total = m + n - 1;

    while (left >= 0)
    {
        if (arr1[left] < arr2[right] && right >= 0)
        {
            arr1[total] = arr2[right];
            right--;
            total--;
        }
        else
        {
            arr1[total] = arr1[left];
            left--;
            total--;
        }
    }
    while (left >= 0)
    {
        arr1[total] = arr1[left];
        total--;
        left--;
    }
    while (right >= 0)
    {
        arr1[total] = arr2[right];
        total--, right--;
    }
    return arr1;
}