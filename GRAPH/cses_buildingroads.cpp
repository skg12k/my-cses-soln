#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define MAXN (int)1e6
#define f(i, M) for (int i = 0; i < M; i++)
#define vi vector<ll>
int n, m;
vector<bool> visited(MAXN, 0);
vi g[MAXN];

void dfs(int v)
{
    visited[v] = true;
    for (int u : g[v])
    {
        if (!visited[u])
            dfs(u);
    }
}
void solve()
{
    cin >> n >> m;
    f(i, m)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vi res;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i), res.pb(i);
        }
    }
    cout << res.size() - 1 << '\n';
    f(i, res.size() - 1)
    {
        cout << res[i] << ' ' << res[i + 1] << '\n';
    }
}
int main()
{

    int tt = 1;
    while (tt--)
    {
        solve();
    }
}