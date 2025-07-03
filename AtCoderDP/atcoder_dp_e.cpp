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
// n -> 100
// v -> 10^3
// w -> 10^9
// n*v -> 10^5
// dp(i,j) -> idx, val required to make minimum weight
void solve()
{

    int n, W;
    cin >> n >> W;
    vi w(n), v(n);
    f(i, n)
    {
        cin >> w[i] >> v[i];
    }
    vector<vector<int>> dp(n, vector<int>(100001, INF));
    dp[0][0] = 0;
    dp[0][v[0]] = w[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = 0;
        for (int j = 0; j < 100001; j++) // for (int j = 100000; j >= 0; j--)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i])
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 100001; i++)
    {
        if ((dp[n - 1][i] != INF) and (dp[n - 1][i] <= W))
        {
            ans = max(ans, i);
        }
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