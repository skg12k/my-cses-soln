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

vector<vector<int>> adj;
vector<bool> vis;
vi res;

bool dfs(int node, int par)
{
    vis[node] = true;
    res.pb(node);
    for (int child : adj[node])
    {
        if (!vis[child])
        {
            if (dfs(child, node))
                return true;
        }
        else if (child != par)
        {
            res.pb(child);
            return true;
        }
    }
    res.pop_back();
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    // important to assign if declaring in global
    adj.assign(n, {});
    vis.assign(n, false);
    f(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            res.clear();
            if (dfs(i, -1))
            {
                found = true;
                break;
            }
        }
    }
    if (!found)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int start = res.back();
    int idx = sz(res) - 2;
    while (res[idx] != start)
        idx--;
    vi ans;
    rep(i, idx, sz(res)) ans.pb(res[i]);
    cout << sz(ans) << endl;
    for (auto i : ans)
        cout << i + 1 << ' ';
    cout << endl;
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
