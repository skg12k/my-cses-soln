#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
// coordinate compression used
void solve()
{
    int n;
    cin >> n;
    pair<long long, pair<long long, long long>> arr[n];
    for (int i = 0; i < n; i++)
    {
        long long l, r, p;
        cin >> l >> r >> p;
        arr[i] = MP(l, MP(r, p));
    }
    sort(arr, arr + n);
    long long dp[n + 1];
    for (int i = n; i >= 0; i--)
    {
        if (i == n)
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = dp[i + 1];
            long long nextVal = arr[i].second.first;
            auto it = upper_bound(arr, arr + n, MP(nextVal, MP(1e9, 1e9)), [](const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
                                  { return a.first < b.first; }) -
                      arr;

            dp[i] = max(dp[i], arr[i].second.second + dp[it]);
        }
    }
    cout << dp[0] << endl;
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