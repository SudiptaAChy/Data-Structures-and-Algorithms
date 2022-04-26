/**
 * http://www.shafaetsplanet.com/?p=3602
 *
 * Time = O(n*m) = O(n^2)
 * Memory = O(n*m) = O(n^2)
 * n = length of string 's'
 * m = length of string 'w'
 *
 */

#include <bits/stdc++.h>
using namespace std;

string s, w, ans[1009][1009];
int dp[1009][1009];

int LCSRecursive(int i, int j)
{
    if (i == s.size() || j == w.size())
        return 0;
    int &ret = dp[i][j];
    if (ret != -1)
        return ret;
    ret = 0;
    if (s[i] == w[j])
        ret = 1 + LCSRecursive(i + 1, j + 1);
    else
        ret = max(LCSRecursive(i + 1, j), LCSRecursive(i, j + 1));
    return ret;
}

int LCSIterative()
{
    int n = s.size();
    int m = w.size();

    // for (int i = 0; i < n; i++)
    //     dp[i][m] = 0;
    // for (int i = 0; i < m; i++)
    //     dp[n][i] = 0;
    memset(dp, 0, sizeof dp);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s[i] == w[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    return dp[0][0];
}

string PrintLCS()
{
    string res = "";

    int n = s.size(), m = w.size();
    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (s[i] == w[j])
        {
            res += s[i];
            i++, j++;
        }
        else if (dp[i + 1][j] > dp[i][j + 1])
            i++;
        else
            j++;
    }

    return res;
}

// alternate LIS with path printing method
void LisWithPathPrinting(string s, string w)
{
    int n = s.size();
    int m = w.size();

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
        ans[i][0] = "";
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
        ans[0][i] = "";
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == w[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans[i][j] = ans[i - 1][j - 1] + s[i - 1];
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
                ans[i][j] = ans[i - 1][j];
            }
            else if (dp[i][j - 1] > dp[i - 1][j])
            {
                dp[i][j] = dp[i][j - 1];
                ans[i][j] = ans[i][j - 1];
            }
            else
            {
                dp[i][j] = dp[i - 1][j]; // it also can be dp[i][j-1]
                ans[i][j] = min(ans[i - 1][j], ans[i][j - 1]);
            }
        }
    }

    if (dp[n][m] == 0)
        puts("no path");
    else
    {
        cout << ans[n][m] << endl;
    }
}

int main()
{
    s = "HELLOM";
    w = "HMRLL";

    // for recursive approach
    memset(dp, -1, sizeof dp);
    cout << LCSRecursive(0, 0) << endl;

    // for iterative approach
    cout << LCSIterative() << endl;

    // for print the LCS string
    cout << PrintLCS() << endl;
    return 0;
}
