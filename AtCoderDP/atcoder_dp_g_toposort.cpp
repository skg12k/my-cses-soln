#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;
const int MAXN = 3e5;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define f(i, n) for (int i = 0; i < n; ++i)
#define sz(x) (int)x.size()
#define ff first
#define ss second
#define endl '\n'
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    vi in(n, 0);
    f(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].pb(y);
        in[y]++;
    }
    vi dp(n, -1);
    queue<int> q;
    f(i, n)
    {
        if (in[i] == 0)
        {
            q.push(i);
            dp[i] = 0;
        }
    }
    vi topo;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.pb(u);
        for (auto child : adj[u])
        {
            in[child]--;
            if (in[child] == 0)
            {
                q.push(child);
            }
        }
    }
    // vector<int> parent(n, -1); for backtracking
    for (auto u : topo)
    {
        for (auto v : adj[u])
        {
            if (dp[v] - dp[u] < 1)
            {
                dp[v] = dp[u] + 1;
                // parent[v] = u;
            }
        }
    }
    /* int mx = -1, end = -1;
    f(i, n)
    {
        if (dp[i] > mx)
        {
            mx = dp[i];
            end = i;
        }
    }
    vi path;
    for (int u = end; u != -1; u = parent[u])
    {
        path.pb(u);
    }
    reverse(all(path));
    for (auto i : path)
    {
        cout << i + 1 << ' ';
    }
    cout << endl; */
    cout << *max_element(all(dp));
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    while (tt--)
    {
        solve();
    }
}