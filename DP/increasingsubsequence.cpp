#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int> dp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end())
        {
            dp.push_back(x);
        }
        else
        {
            *it = x;
        }
    }
    cout << dp.size() << endl;
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