/**
 * http://www.shafaetsplanet.com/?p=3638
 */

#include <bits/stdc++.h>
using namespace std;
int n, cap;
int cost[100], weight[100];
int dp[100][100];
int knap(int i, int w)
{
    if (i == n)
        return 0;
    int profit1 = 0, profit2 = 0;
    if (dp[i][w] != -1)
        return dp[i][w];
    if (w + weight[i] <= cap)
        profit1 = cost[i] + knap(i + 1, w + weight[i]);
    profit2 = knap(i + 1, w);
    return dp[i][w] = max(profit1, profit2);
}
main()
{
    memset(dp, -1, sizeof dp);
    cin >> n >> cap;
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> cost[i];
    cout << knap(0, 0) << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= cap; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}
