#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    double x = (double)a.second / (double)a.first;
    double y = (double)b.second / (double)b.first;
    return x > y;
}

double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), compare);
    double val = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (items[i].first <= w)
        {
            w -= items[i].first;
            val += items[i].second;
        }
        else
        {
            val += (items[i].second * ((double)w / items[i].first));
            break;
        }
    }
    return val;
}