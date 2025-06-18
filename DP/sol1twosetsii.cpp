#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve()
{
    int N;
    cin >> N;
    int target = N * (N + 1) / 2;
    long long dp[N + 1][target + 1];
    memset(dp, 0, sizeof dp);
    if (target % 2)
    {
        cout << 0 << endl;
        return;
    }
    target = target / 2;
    dp[0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= i)
            {
                (dp[i][j] += dp[i - 1][j - i]) %= MOD;
            }
        }
    }
    cout << dp[N - 1][target] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    while (tt--)
    {
        solve();
    }
    return 0;
}