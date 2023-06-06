#include <bits/stdc++.h>
using namespace std;

// Approach 1

int LongestSubsetWithZeroSum(vector<int> arr)
{

    int maxi = 0, sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == 0)
                maxi = max(maxi, j - i + 1);
        }
    }
    return maxi;
}

// Approach 2
int LongestSubsetWithZeroSum(vector<int> arr)
{

    int maxi = 0;
    int sum = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
            maxi = i + 1;
        else
        {
            if (map.find(sum) != map.end())
                maxi = max(maxi, i - map[sum]);
            else
                map[sum] = i;
        }
    }
    return maxi;
}