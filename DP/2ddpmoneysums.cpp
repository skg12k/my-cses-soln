#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
    }
    int max_s = accumulate(X.begin(), X.end(), 0);
    int dp[N + 1][max_s + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= max_s; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= X[i - 1] && dp[i - 1][j - X[i - 1]])
            {
                dp[i][j] = 1;
            }
        }
    }
    vector<int> ans;
    for (int j = 1; j <= max_s; j++)
    {
        if (dp[N][j] == 1)
        {
            ans.push_back(j);
        }
    }
    cout << ans.size() << endl;
    for (int v : ans)
    {
        cout << v << ' ';
    }
    cout << endl;
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