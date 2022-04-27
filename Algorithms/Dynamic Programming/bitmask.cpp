/**
 * http://www.shafaetsplanet.com/?p=1357
 * https://lightoj.com/problem/pimp-my-ride
 *
 * Time = O((2^n)*(n^2))
 * Memory = O(2^n)
 */

#include <bits/stdc++.h>
using namespace std;

int dp[(1 << 15) + 2];

int Set(int N, int pos) { return N = N | (1 << pos); }
bool Check(int N, int pos) { return (bool)(N & (1 << pos)); }
int Reset(int N, int pos) { return N = N & ~(1 << pos); }

int bitMask(int mask, int price[3][3], int n)
{
    if (mask == (1 << n) - 1)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (Check(mask, i) == 0)
        {
            int p = price[i][i];
            for (int j = 0; j < n; j++)
            {
                if (i != j && Check(mask, j) != 0)
                    p += price[i][j];
            }
            ans = min(ans, p + bitMask(Set(mask, i), price, n));
        }
    }

    return dp[mask] = ans;
}
int main()
{
    memset(dp, -1, sizeof dp);
    int n = 3;
    int price[3][3] = {
        {14, 23, 0}, {0, 14, 0}, {1000, 9500, 14}};
    cout << bitMask(0, price, n) << endl;
    return 0;
}
