#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e6;
void solve()
{
    int n;
    cin >> n;
    int dp[n + 1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i >= j)
            {
                (dp[i] += dp[i - j]) %= MOD;
            }
        }
    }
    cout << dp[n] << endl;
}
int main()
{
    int tt = 1;
    while (tt--)
    {
        solve();
    }
}