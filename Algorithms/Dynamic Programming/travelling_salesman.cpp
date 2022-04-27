/**
 * http://www.shafaetsplanet.com/?p=3721
 * Time = O(n^2*2^n)
 * Memory = O(n*2^n)
 */

#include <bits/stdc++.h>
#define inf 1061109567

using namespace std;

const int N = 20;
int dp[N][(1 << N) + 2], n = 5;
int graph[5][5] = {
    {inf, 1, inf, 9, inf},
    {inf, inf, 3, inf, inf},
    {inf, inf, inf, 4, 2},
    {inf, 2, inf, inf, 3},
    {4, inf, inf, inf, inf},
};

int Set(int N, int pos) { return N = N | (1 << pos); }
bool Check(int N, int pos) { return (bool)(N & (1 << pos)); }
int Reset(int N, int pos) { return N = N & ~(1 << pos); }

int func(int i, int mask)
{
    if (mask == (1 << n) - 1)
    {
        return graph[i][0];
    }

    if (dp[i][mask] != -1)
    {
        return dp[i][mask];
    }

    int ans = inf;
    for (int j = 0; j < n; j++)
    {
        if (graph[i][j] == inf)
            continue;

        if (Check(mask, j) == 0)
        {
            int result = func(j, Set(mask, j)) + graph[i][j];
            ans = min(ans, result);
        }
    }

    return dp[i][mask] = ans;
}

int main()
{
    memset(dp, -1, sizeof dp);
    cout << func(0, 1) << endl; // 0->1->2->3->4 = 15
    return 0;
}
