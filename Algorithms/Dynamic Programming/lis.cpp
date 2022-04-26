/**
 * http://www.shafaetsplanet.com/?p=1211
 *
 * Time = O(n^2)
 * Memory = O(n^2)
 * n = length of string array
 *
 */

#include <bits/stdc++.h>
using namespace std;

string s, w;
int dp[1009], next_index[1009], start_index;

int f(int i, vector<int> v)
{
    if (i == v.size() - 1)
        return 1;

    int &ret = dp[i];
    if (ret != -1)
        return ret;

    int ans = 0;
    for (int j = i + 1; j < v.size(); j++)
    {
        if (v[j] > v[i])
        {
            int subResult = f(j, v);
            if (subResult > ans)
            {
                ans = subResult;
                next_index[i] = j;
            }
        }
    }

    return ret = ans + 1;
}

// recursive approach to find LIS
int findLis(vector<int> v)
{
    memset(dp, -1, sizeof dp);
    memset(next_index, -1, sizeof next_index);
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int res = f(i, v);
        if (res > ans)
        {
            ans = res;
            start_index = i;
        }
    }
    return ans;
}

// iterative approach to find LIS
int iterativeLIS(vector<int> v)
{
    for (int i = v.size() - 1; i >= 0; i--)
    {
        int ans = 0;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] > v[i])
            {
                ans = max(ans, dp[j]);
            }
        }
        dp[i] = ans + 1;
    }

    int ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans = max(ans, dp[i]);
    return ans;
}

// print the Longest Increasing Subsequence
void printLis(vector<int> v)
{
    vector<int> lis;
    while (start_index != -1)
    {
        lis.push_back(v[start_index]);
        start_index = next_index[start_index];
    }
    for (auto it : lis)
        cout << it << " ";
    cout << endl;
}

int main()
{
    vector<int> v = {5, 0, 9, 2, 7, 3, 4};
    cout << findLis(v) << endl;
    // cout << iterativeLIS(v) << endl;
    printLis(v);
    return 0;
}
