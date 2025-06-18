#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e6;
void solve()
{
    long long N, M;
    cin >> N >> M;
    vector<long long> A(N + 1);
    long long dp[N + 2][M + 2];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (long long i = 1; i <= N; i++)
    {
        for (long long x = 1; x <= M; x++)
        {
            if (i == 1)
            {
                if (A[i] == 0 || A[i] == x)
                {
                    dp[i][x] = 1;
                }
                else
                    dp[i][x] = 0;
            }
            else
            {
                if (A[i] == 0 || A[i] == x)
                {
                    (dp[i][x] = dp[i - 1][x - 1] % MOD + dp[i - 1][x] % MOD + dp[i - 1][x + 1] % MOD) %= MOD;
                }
                else
                    dp[i][x] = 0;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= M; i++)
    {
        (ans = ans + dp[N][i]) %= MOD;
    }
    cout << ans << endl;
}
int main()
{
    int tt = 1;
    while (tt--)
    {
        solve();
    }
}