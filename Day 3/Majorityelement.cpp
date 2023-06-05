#include <bits/stdc++.h>
using namespace std;
int findMajorityElement(int arr[], int n)
{
    map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for (auto it : count)
    {
        if (it.second > n / 2)
            return it.first;
    }
    return -1;
}