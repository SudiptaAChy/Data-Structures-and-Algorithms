/**
 * http://zobayer.blogspot.com/2009/08/calculate-ncr-using-dp.html
 * Time = O(n*r)
 * Memory = O(n*r)
 */

#include <bits/stdc++.h>
#define ll long long
ll dp[66][33];

ll nCr(int n, int r)
{
    if (n == r)
        return dp[n][r] = 1;
    if (r == 0)
        return dp[n][r] = 1;
    if (r == 1)
        return dp[n][r] = (ll)n;
    if (dp[n][r])
        return dp[n][r];
    return dp[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);
}

int main()
{
    printf("%lld\n", nCr(10, .3));
    return 0;
}
