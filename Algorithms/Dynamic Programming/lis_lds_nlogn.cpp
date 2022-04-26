/**
 * https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
 * https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
 *
 * Time = O(nlogn)
 * Memory = O(n)
 * n = length of string array
 *
 */

#include <bits/stdc++.h>
using namespace std;

int LongestIncreasingSubsequenceLength(vector<int> &v)
{
    if (v.size() == 0) // boundary case
        return 0;

    vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail

    tail[0] = v[0];

    for (int i = 1; i < v.size(); i++)
    {

        // Do binary search for the element in
        // the range from begin to begin + length
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, v[i]);

        // If not present change the tail element to v[i]
        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }

    return length;
}

int LIS(vector<int> const &a)
{
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n + 1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j - 1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

// Longest Decreasing Sequence is just LIS from the reverse side of array
int LDS(vector<int> const &a)
{
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n + 1, INF);
    d[0] = -INF;

    for (int i = n - 1; i >= 0; i--)
    {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j - 1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

int main()
{
    vector<int> v{2, 5, 3, 7, 11, 8, 10, 13, 6};
    cout << LongestIncreasingSubsequenceLength(v) << endl;
    cout << LIS(v) << endl;
    cout << LDS(v) << endl;
    return 0;
}
