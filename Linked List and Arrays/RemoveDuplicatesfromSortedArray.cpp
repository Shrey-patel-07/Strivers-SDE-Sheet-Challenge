#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n)
{
    // Write your code here.
    int a = -1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != a)
        {
            a = arr[i];
            count++;
        }
    }
    return count;
}