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
    f(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].pb(y);
    }
    vi dp(n, -1);
    function<void(int)> dfs = [&](int src) -> int
    {
        if (dp[src] != -1)
            return (dp[src]);
        int mx = 0;
        for (auto child : adj[src])
        {
            dfs(child);
            mx = max(dp[child] + 1, mx);
        }
        return dp[src] = mx;
    };
    for (int i = 0; i < n; ++i)
    {
        dfs(i);
    }
    int ans = 0;
    for (auto ele : dp)
    {
        ans = max(ans, ele);
    }
    cout << ans;
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