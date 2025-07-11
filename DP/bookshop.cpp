#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - h[i - 1] >= 0)
            {
                dp[i][j] = max(dp[i][j], s[i - 1] + dp[i - 1][j - h[i - 1]]);
            }
        }
    }
    cout << dp[n][x] << endl;
}
int main()
{
    int tt = 1;
    while (tt--)
    {
        solve();
    }
}