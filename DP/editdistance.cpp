#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long MAXN = 1e6;
void solve()
{
    string S1, S2;
    cin >> S1 >> S2;
    int N = S1.size();
    int M = S2.size();
    S1 = " " + S1;
    S2 = " " + S2;

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= M; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (S1[i] == S2[j])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j],
                                dp[i][j - 1],
                                dp[i - 1][j - 1]}) +
                           1;
            }
        }
    }

    cout << dp[N][M] << '\n';
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