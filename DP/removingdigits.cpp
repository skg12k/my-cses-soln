#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
void solve()
{
    int n;
    cin >> n;
    vi dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (char c : to_string(i))
        {
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }
    }
    cout << dp[n] << endl;
}
int main()
{
    int tt = 1;
    while (tt--)
    {
        solve();
    }
}