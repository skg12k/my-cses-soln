#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main()
{

    int n;
    cin >> n;

    int total = n * (n + 1) / 2;
    if (total % 2 != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int target = total / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int num = 1; num <= n; ++num)
    {
        for (int sum = target; sum >= num; --sum)
        {
            dp[sum] = (dp[sum] + dp[sum - num]) % mod;
        }
    }

    // We divide by 2 because every valid subset pair is counted twice
    int inv2 = (mod + 1) / 2; // Modular inverse of 2 mod 1e9+7
    cout << (1LL * dp[target] * inv2 % mod) << endl;
}