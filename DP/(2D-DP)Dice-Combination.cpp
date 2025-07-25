#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

void solve()
{
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    vi dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6 && i - j >= 0; j++)
        {
            (dp[i] += dp[i - j]) %= mod;
        }
    }
    cout << dp[n] << endl;
    return;
}
int main()
{
    solve();
}