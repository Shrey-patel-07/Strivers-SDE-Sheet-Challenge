#include <bits/stdc++.h>
using namespace std;

bool f(vector<int> &arr, int ind, int target, int n, int sum, int count)
{
    if (count == 4)
        return sum == target;
    if (ind > n)
        return false;

    bool not_take = f(arr, ind + 1, target, n, sum, count);
    bool take = false;
    if (count < 4)
        take = f(arr, ind + 1, target, n, sum + arr[ind], count + 1);

    return take || not_take;
}

string fourSum(vector<int> arr, int target, int n)
{
    return f(arr, 0, target, n, 0, 0) ? "Yes" : "No";
}
