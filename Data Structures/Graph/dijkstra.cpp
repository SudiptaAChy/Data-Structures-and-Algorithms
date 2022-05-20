/**
 * http://www.shafaetsplanet.com/?p=1500
 *
 * Time = O(VlogV + E)
 * Space = O(V + E)
 */

#include <bits/stdc++.h>
#define sz 1000009
#define pii pair<int, int>
#define ll long long
using namespace std;
vector<pii> v[sz];
vector<int> dis(sz, INT_MAX);
map<int, int> parent;
void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq; /// sorting in ascending order in base of first element of pair
    pq.push(make_pair(0, s));                          /// weight - node
    dis[s] = 0;
    while (!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        int d = top.first, u = top.second;
        for (auto it : v[u])
        {
            int v1 = it.first, v2 = it.second; /// v1 = node v2 = weight as pair
            if (dis[u] + v2 < dis[v1])
            {
                dis[v1] = dis[u] + v2;
                parent[v1] = u;
                pq.push(make_pair(dis[v1], v1));
            }
        }
    }
}
main()
{
    int n, e, x, y, w;
    cin >> n >> e;
    while (e--)
    {
        cin >> x >> y >> w;
        v[x].push_back(make_pair(y, w));
        v[y].push_back(make_pair(x, w));
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
        cout << dis[i] << endl;
    return 0;
}
/*

9 14
0 1 4
0 7 8
1 7 11
1 2 8
7 6 1
7 8 7
8 6 6
8 2 2
2 3 7
2 5 4
3 5 14
3 4 9
5 4 10
6 5 2

*/
