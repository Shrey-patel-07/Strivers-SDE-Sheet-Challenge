#include <bits/stdc++.h>
using namespace std;
int findMinimumCoins(int amount)
{
    vector<int> currency = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int coin = 0;
    int i = 8;
    while (amount > 0 && i >= 0)
    {
        if (amount < currency[i])
        {
            i--;
            continue;
        }
        coin++;
        amount -= currency[i];
    }
    return coin;
}
