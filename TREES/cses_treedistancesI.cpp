#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;
const int MAXN = 3e5;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

#define dbg(x) cerr << #x << " = " << (x) << endl;
#define dbgv(v)             \
    cerr << #v << " = [ ";  \
    for (auto &ele : v)     \
        cerr << ele << " "; \
    cerr << "]" << endl;

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
vector<vector<int>> adj;
vi depth, ans;
void depthh(int src, int par)
{
    int maxdepth = 0;
    bool leaf = 1;
    for (auto child : adj[src])
    {
        if (child != par)
        {
            leaf = 0;
            depthh(child, src);
            maxdepth = max(maxdepth, depth[child]);
        }
    }
    if (leaf)
    {
        depth[src] = 0;
    }
    else
    {
        depth[src] = 1 + maxdepth;
    }
}

void anss(int src, int par, int par_ans)
{
    vi pref, suf;
    for (int child : adj[src])
    {
        if (child != par)
        {
            pref.pb(depth[child]);
            suf.pb(depth[child]);
        }
    }
    rep(i, 1, sz(pref))
    {
        pref[i] = max(pref[i], pref[i - 1]);
    }
    rrep(i, sz(pref) - 2, 0)
    {
        suf[i] = max(suf[i], suf[i + 1]);
    }
    int cno = 1; // corresponds to childs
    for (int child : adj[src])
    {
        if (child != par)
        {
            int op1 = (cno == 1) ? INT_MIN : pref[cno - 2];
            int op2 = (cno == sz(pref)) ? INT_MIN : suf[cno];
            int partial_ans = 1 + max(par_ans, max(op1, op2));
            anss(child, src, partial_ans);
            cno++;
        }
    }
    ans[src] = max(1 + par_ans, depth[src]);
}

void solve()
{
    cin >> n;
    adj.resize(n), depth.resize(n), ans.resize(n);
    f(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b), adj[b].pb(a);
    }
    depthh(0, -1);
    anss(0, -1, -1);
    for (auto i : ans)
    {
        cout << i << ' ';
    }
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