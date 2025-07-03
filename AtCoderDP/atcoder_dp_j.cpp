#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;
const int MAXN = 3e5;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define f(i, n) for (int i = 0; i < n; ++i)
#define sz(x) (int)x.size()
#define ff first
#define ss second
#define endl '\n'
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define pb push_back

int n;
long double dp[301][301][301];

double memo(int x, int y, int z)
{
    if (x < 0 || y < 0 || z < 0)
    {
        return 0;
    }
    if (x == 0 && y == 0 && z == 0)
        return 0;
    if (dp[x][y][z] > 0)
    {
        return dp[x][y][z];
    }

    long double ret = n + x * memo(x - 1, y, z) + y * memo(x + 1, y - 1, z) + z * memo(x, y + 1, z - 1);
    return dp[x][y][z] = ret / (x + y + z);
}
void solve()
{
    cin >> n;
    vi a(n);
    f(i, n) cin >> a[i];
    vi freq(3);
    for (int x : a)
    {
        freq[x - 1]++;
    }
    memset(dp, -1, sizeof dp);
    cout << fixed << setprecision(9) << memo(freq[0], freq[1], freq[2]) << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    while (tt--)
    {
        solve();
    }
}