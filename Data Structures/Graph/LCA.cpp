/**
 * http://www.shafaetsplanet.com/planetcoding/?p=1831
 *
 * Time: O(NlogN + QlogN) ;NlogN for pre-processing QlogN for each query result
 * Memory: O(N)
 */

#include <bits/stdc++.h>
#define mx 100002
using namespace std;

vector<int> g[mx];
int L[mx], P[mx][30], T[mx];

void dfs(int from, int u, int dep)
{
    T[u] = from;
    L[u] = dep;
    for (auto v : g[u])
    {
        if (v != from)
            dfs(u, v, dep + 1);
    }
}

void lca_init(int N)
{
    memset(P, -1, sizeof P);
    for (int i = 0; i < N; i++)
        P[i][0] = T[i];
    for (int j = 1; (1 << j) < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i - 1][j - 1]][j - 1];
        }
    }
}

int lca_query(int p, int q)
{
    if (L[p] < L[q])
        swap(p, q);

    int log = 1;
    while (true)
    {
        int next = log + 1;
        if ((1 << next) > L[p])
            break;
        log++;
    }

    // cout << "log = " << log << endl;

    for (int i = log; i >= 0; i--)
    {
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];
    }

    if (p == q)
        return p;

    for (int i = log; i >= 0; i--)
    {
        if (P[p][i] != -1 && P[p][i] != P[q][i])
        {
            p = P[p][i];
            q = P[q][i];
        }
    }

    return T[p];
}

int main()
{
    g[0].push_back(1);
    g[0].push_back(2);
    g[2].push_back(3);
    g[2].push_back(4);
    dfs(0, 0, 0);
    lca_init(5);
    printf("%d\n", lca_query(3, 4));
    return 0;
}
