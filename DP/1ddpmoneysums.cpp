#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int max_sum = accumulate(x.begin(), x.end(), 0);
    vector<int> dp(max_sum + 1, 0);
    dp[0] = 1;

    for (int coin : x)
    {
        for (int i = max_sum; i >= coin; i--) // reverse to avoid overcounting
        {
            if (dp[i - coin])
                dp[i] = 1;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= max_sum; i++)
    {
        if (dp[i])
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    solve();
    return 0;
}