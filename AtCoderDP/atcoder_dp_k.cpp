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
    int n, k;
    cin >> n >> k;
    vi a(n);
    f(i, n) cin >> a[i];
    vector<bool> dp(k + 1);
    dp[0] = 0; // BASE Freaking CASE, thought on this for a while ngl
    for (int i = 1; i <= k; i++)
    {
        for (int j : a)
        {
            if (i >= j and !dp[i - j])
            {
                dp[i] = 1;
            }
        }
    }
    cout << (dp[k] ? "First" : "Second");
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