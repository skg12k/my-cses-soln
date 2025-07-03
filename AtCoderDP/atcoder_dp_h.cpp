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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    vector<vector<int>> dp(h, vector<int>(w));
    f(i, h) f(j, w) cin >> grid[i][j];
    auto isValid = [&](int x, int y)
    {
        if (x < 0 || x >= h || y < 0 || y >= w)
            return false;
        if (grid[x][y] == '#')
            return false;
        return true;
    };
    dp[0][0] = 1;
    f(i, h)
    {
        f(j, w)
        {
            if (isValid(i - 1, j))
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
            if (isValid(i, j - 1))
            {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    cout << dp[h - 1][w - 1] % MOD;
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