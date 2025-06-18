#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
    for (int i = 1; i <= a; i++)
    {
        dp[i][1] = i - 1;
    }
    for (int i = 1; i <= b; i++)
    {
        dp[1][i] = i - 1;
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                for (int k = 1; k <= i - 1; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
                }
                for (int l = 1; l <= j - 1; l++)
                {
                    dp[i][j] = min(dp[i][j - l] + dp[i][l] + 1, dp[i][j]);
                }
            }
        }
    }
    cout << dp[a][b] << endl;
}
int main()
{
    solve();
    return 0;
}