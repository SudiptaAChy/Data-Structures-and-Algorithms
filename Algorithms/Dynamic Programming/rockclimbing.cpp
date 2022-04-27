/**
 * http://www.shafaetsplanet.com/?p=1158
 *
 * Time = O(n*m)
 * Memory = O(n*m)
 *
 * 3 directional grid
 * 4 directional move not allowed cz cycle is created
 */

#include <bits/stdc++.h>
using namespace std;
int mat[][10] = {
    {-1, 2, 5},
    {4, -2, 3},
    {1, 2, 10}};
int r = 3, c = 3;
int dp[10][10];
int call(int i, int j)
{
    if (i >= 0 && i < r && j >= 0 && j < c)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        int ret = INT_MIN;
        ret = max(ret, call(i + 1, j) + mat[i][j]);
        ret = max(ret, call(i + 1, j - 1) + mat[i][j]);
        ret = max(ret, call(i + 1, j + 1) + mat[i][j]);
        return dp[i][j] = ret;
    }
    else
        return 0;
}
main()
{
    memset(dp, -1, sizeof dp);
    printf("%d\n", call(0, 0));
}
