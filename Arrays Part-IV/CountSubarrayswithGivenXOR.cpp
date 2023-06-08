#include <bits/stdc++.h>
using namespace std;

// Approach 1 (giving TLE)
int subarraysXor(vector<int> &arr, int x)
{
    int maxi = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int xxor = 0;
        for (int j = i; j < arr.size(); j++)
        {
            xxor = xxor ^ arr[j];
            if (xxor == x)
                maxi++;
        }
    }
    return maxi;
    //    Write your code here.
}

// Approach 2
int subarraysXor(vector<int> &arr, int x)
{
    int xxor = 0;
    map<int, int> visited;
    visited[xxor]++;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xxor = xxor ^ arr[i];
        int a = xxor ^ x;
        cnt += visited[a];
        visited[xxor]++;
    }
    return cnt;
    //    Write your code here.
}