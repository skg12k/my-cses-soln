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

int n, m;
int dp[1001][1 << 11];
bool vis[1001][1 << 11];

void gen_mask(int cur_mask, int i, int next_mask, vector<int> &masks)
{
    if (i == n)
    {
        masks.pb(next_mask);
        return;
    }
    if ((cur_mask >> i) & 1)
    {
        gen_mask(cur_mask, i + 1, next_mask, masks);
    }
    else
    {
        gen_mask(cur_mask, i + 1, next_mask | (1 << i), masks);
        if (i + 1 < n && ((cur_mask >> (i + 1)) & 1) == 0)
        {
            gen_mask(cur_mask, i + 2, next_mask, masks);
        }
    }
}

int memo(int col, int mask)
{

    if (col == m)
        return (mask == 0);

    if (vis[col][mask])
        return dp[col][mask];
    vis[col][mask] = 1;
    int &res = dp[col][mask];

    vector<int> allmask;
    gen_mask(mask, 0, 0, allmask);

    for (int nm : allmask)
    {
        res = (res + memo(col + 1, nm)) % MOD;
    }
    return res;
}

void solve()
{
    cin >> n >> m;
    cout << memo(0, 0) << endl;
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