/**
 * https://www.youtube.com/watch?v=aAALKHLeexw
 * http://www.shafaetsplanet.com/planetcoding/?p=1961
 * https://www.topcoder.com/thrive/articles/Binary%20Indexed%20Trees
 *
 * Time = O(NlogN)
 * update = query = O(logN)
 * Memory = O(N)
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e3 + 9;
int a[N], tree[N];
void Update(int idx, int x, int n) // O(logN)
{
    while (idx <= n)
    {
        tree[idx] += x;
        idx += (idx & -idx);
    }
}
int Query(int idx) // O(logN)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int main()
{
    int a[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 1; i <= n; i++)
        Update(i, a[i - 1], n);
    cout << "Sum upto idx 5 = " << Query(5) << endl;
    Update(3, 4, n);
    cout << "Sum upto idx 5 = " << Query(5) << endl;
    return 0;
}
