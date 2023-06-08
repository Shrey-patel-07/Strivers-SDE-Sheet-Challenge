#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high)
{
    int ans = 0;
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && arr[i] > arr[j] * 2)
        {
            j++;
        }
        ans += (j - (mid + 1));
    }

    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return ans;
}

int mergesort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return 0;
    int mid = (low + high) / 2;
    int x = mergesort(arr, low, mid);
    x += mergesort(arr, mid + 1, high);
    x += merge(arr, low, mid, high);
    return x;
}

int reversePairs(vector<int> &arr, int n)
{
    // Write your code here.
    mergesort(arr, 0, arr.size() - 1);
}