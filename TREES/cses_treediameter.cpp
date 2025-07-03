// i know that i am not that important to you
// but to me you girl you are so much more than gorgeous
// so much more than perfect
// rn ik that i am not really worth it
// if u give me time, i cd work on it

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

int n;
vector<int> diameter;
vector<vector<int>> adj;
vector<int> downpath;
void eval_downpaths(int src, int par)
{
    int bestkid = 0;
    bool leaf = 1;
    for (auto child : adj[src])
    {
        if (child != par)
        {
            leaf = 0;
            eval_downpaths(child, src);
            bestkid = max(bestkid, downpath[src]);
        }
    }
    if (leaf)
        downpath[src] = 0;
    downpath[src] = 1 + bestkid;
}
void solve()
{
    cin >> n;
    adj.resize(n);
    downpath.resize(n);
    diameter.resize(n);
    f(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b), adj[b].pb(a);
    }
    function<void(int, int)> dfs = [&](int src, int par) -> void
    {
        int ans = 0;
        vi childrendownpath;
        bool leaf = 1;
        for (auto child : adj[src])
        {
            if (child != par)
            {

                dfs(child, src);
                childrendownpath.pb(downpath[child]);
                ans = max(ans, diameter[child]);
            }
        }
        int numofchil = childrendownpath.size();
        sort(all(childrendownpath));
        if (numofchil == 0)
            diameter[src] = 0;
        if (numofchil == 1)
    };
    dfs(0, -1);
    cout << max(dp[0][1], dp[0][0]);
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