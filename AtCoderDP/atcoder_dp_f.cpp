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
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(sz(s), vector<int>(sz(t), 0));
    dp[0][0] = (s[0] == t[0]);
    for (int i = 0; i < sz(s); i++)
        dp[i][0] = (s[i] == t[0] ? 1 : (i > 0 ? dp[i - 1][0] : 0));
    for (int j = 0; j < sz(t); j++)
        dp[0][j] = (s[0] == t[j] ? 1 : (j > 0 ? dp[0][j - 1] : 0));
    for (int i = 1; i < sz(s); i++)
        for (int j = 1; j < sz(t); j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + (s[i] == t[j]);
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
        }

    string ans = "";
    int i = sz(s) - 1;
    int j = sz(t) - 1;
    while (i >= 0 && j >= 0) // back tracking
    {
        if (s[i] == t[j])
        {
            ans += s[i];
            i--, j--;
        }
        else if (i > 0 && dp[i][j] == dp[i - 1][j]) // as dp[i-1][j] = dp[i][j] ith idx wouldnt have
                                                    // created a change hence we skip over it
        {
            i--;
        }
        else
            j--;
    }
    reverse(all(ans));
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