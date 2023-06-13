#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m)
{
    // Write your code here.
    long long ans = 1;
    long temp = x;
    while (n > 0)
    {
        if (n % 2 != 0)
        {
            ans = ((ans) % m * (temp) % m) % m;
        }
        temp = ((temp) % m * (temp) % m) % m;
        n = n >> 1;
    }
    return ans % m;
}