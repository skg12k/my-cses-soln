#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<long long> X(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> X[i];
    }
    long long dp[N + 2][N + 2];

    for (int i = 1; i <= N; i++)
    {
        dp[i][i] = X[i];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (j - i == 1 || i - j == 1)
            {
                dp[i][j] = max(X[i], X[j]);
            }
        }
    }
    for (int i = N; i >= 1; i--)
    {
        for (int j = i + 1; j <= N; j++)
        {
            long long pick1 = X[i] + min((i + 2 <= j ? dp[i + 2][j] : 0LL), (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0LL));
            long long pick2 = X[j] + min((i <= j - 2 ? dp[i][j - 2] : 0LL), (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0LL));
            dp[i][j] = max(pick1, pick2);
        }
    }
    cout << dp[1][N] << endl;
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