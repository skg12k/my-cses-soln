#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= c[j])
            {
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    if (dp[x] == 1e9)
        cout << -1 << endl;
    else
        cout << dp[x] << endl;
}
int main()
{
    int tt = 1;
    while (tt--)
    {
        solve();
    }
}
