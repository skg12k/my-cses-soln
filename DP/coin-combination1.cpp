#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= c[j])
            {
                (dp[i] += dp[i - c[j]]) %= MOD;
            }
        }
    }
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