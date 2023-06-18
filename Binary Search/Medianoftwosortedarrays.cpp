#include <bits/stdc++.h>
using namespace std;

double median(vector<int> &a, vector<int> &b)
{
    // Write your code here.
    int x = a.size(), y = b.size();
    if (x > y)
        return median(b, a);

    int low = 0, high = x, md = ((x + y + 1) / 2);
    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = md - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int r1 = (cut1 == x) ? INT_MAX : a[cut1];
        int r2 = (cut1 == y) ? INT_MAX : b[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((x + y) % 2 != 0)
                return max(l1, l2);
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0.0;
}