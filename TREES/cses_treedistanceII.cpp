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
    int n;
    cin >> n;
    vi adj[n];
    f(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b), adj[b].pb(a);
    }
    vi ans(n);
    vi subtreeanss(n);
    function<void(int, int)> dfs = [&](int src, int par) -> void
    {
        int subtreeans = 0;
        for (auto child : adj[src])
        {
            if (child != par)
            {
                dfs(child, src);
                subtreeans += (1 + 2 * subtreeanss[child]);
            }
        }
        subtreeanss[src] = subtreeans;
    };
    function<void(int, int)> dfsforans = [&](int src, int par) -> void {};
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