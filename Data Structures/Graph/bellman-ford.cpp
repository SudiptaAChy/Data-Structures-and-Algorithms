/**
 * http://www.shafaetsplanet.com/planetcoding/?p=2044
 *
 * Time = O(V*E)
 * Space = O(E)
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 123456789101112;
ll dist[1234567];
struct T
{
    ll u, v, w;
} graph[1234567];
void bellmanford(ll s, ll n, ll e)
{
    for (ll i = 0; i < n; i++)
        dist[i] = inf;
    dist[s] = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        for (ll j = 0; j < e; j++)
        {
            ll x = graph[j].u;
            ll y = graph[j].v;
            ll weight = graph[j].w;
            if (dist[x] != inf && dist[x] + weight < dist[y])
                dist[y] = dist[x] + weight;
        }
    }
}
int main(void)
{
    ll n, e, s;
    cin >> n >> e;
    for (ll i = 0; i < e; i++)
    {
        cin >> graph[i].u >> graph[i].v >> graph[i].w;
    }
    cin >> s;
    bellmanford(s, n, e);
    /// negative cycle
    for (ll i = 0; i < e; i++)
    {
        ll x = graph[i].u;
        ll y = graph[i].v;
        ll weight = graph[i].w;
        if (dist[x] != inf && dist[x] + weight < dist[y])
        {
            cout << "Negative cycle detected\n";
            return 0;
        }
    }
    /// print shortest path
    cout << "Vertex from the distance ->\n";
    for (ll i = 0; i <= n; i++)
        cout << i << "\t" << dist[i] << endl;

    return 0;
}
/*
5 10
1 2 6
1 4 7
2 3 5
2 4 8
2 5 -4
3 2 -2
4 3 -3
4 5 9
5 1 2
5 3 7
*/
