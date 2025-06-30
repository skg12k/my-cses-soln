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
    vector<int> adj[n];
    f(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int dp[n][2];
    memset(dp, 0, sizeof dp);
    function<void(int, int)> dfs = [&](int src, int par) -> void
    {
        bool leaf = 1;
        // dp[src][0]
        // dp[src][1]
        for (auto child : adj[src])
        {
            leaf = 0;
            if (child != par)
            {
                dfs(child, src);
            }
        }
        if (leaf)
            return;
        for (auto child : adj[src])
        {
            if (child != par)
                dp[src][0] += max(dp[child][0], dp[child][1]);
        }
        for (auto child : adj[src])
        {
            if (child != par)
                dp[src][1] = max(dp[src][1], 1 + dp[child][0] + dp[src][0] - max(dp[child][0], dp[child][1]));
        }
    };
    dfs(0, -1);
    int ans = max(dp[0][0], dp[0][1]);
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