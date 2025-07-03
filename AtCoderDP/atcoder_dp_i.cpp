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
    vector<double> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    // vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
    vector<double> dp(n + 1, 0); // dp[i] -> i heads
    // dp[i,j] = i trials and j heads
    // dp[0][0] = 1.0;
    dp[0] = 1.0;
    /*
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j >= 0; j--) // for(int j = 0; j<= i ;j++) here j = i / n everything fking works
            {
                if (j > 0)
                    dp[i][j] += dp[i - 1][j - 1] * p[i - 1];
                dp[i][j] += dp[i - 1][j] * (1 - p[i - 1]);
            }
        } */

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j >= 0; j--)
        {
            dp[j] = (dp[j] * (1 - p[i])) + (j > 0 ? dp[j - 1] * p[i] : 0);
        }
    }
    double ans = 0;
    for (int j = n / 2 + 1; j <= n; j += 1)
    {
        //  ans += dp[n][j];
        ans += dp[j];
    }
    cout << fixed << setprecision(10) << ans;
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