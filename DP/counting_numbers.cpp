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

string a, b;
int dp[20][2][2][11][2];
bool vis[20][2][2][11][2];

int memo(int pos, bool tightlo, bool tighthi, int prev, bool leadingzero)
{
    if (pos == a.size())
        return 1;
    if (vis[pos][tightlo][tighthi][prev][leadingzero])
        return dp[pos][tightlo][tighthi][prev][leadingzero];
    vis[pos][tightlo][tighthi][prev][leadingzero] = 1;
    int lo = tightlo ? a[pos] - '0' : 0;
    int hi = tighthi ? b[pos] - '0' : 9;
    int &res = dp[pos][tightlo][tighthi][prev][leadingzero];
    for (int d = lo; d <= hi; d++)
    {
        if (d == prev)
            continue;
        int ntl = tightlo && (d == lo);
        int nth = tighthi && (d == hi);
        bool nlz = leadingzero & (d == 0);
        if (nlz)
        {
            res += memo(pos + 1, ntl, nth, -1, nlz);
        }

        else
        {
            res += memo(pos + 1, ntl, nth, d, 0);
        }
    }
    return res;
}
void solve()
{
    cin >> a >> b;
    while (a.size() < b.size())
    {
        a = "0" + a;
    }
    cout << memo(0, 1, 1, -1, 1) << endl;
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