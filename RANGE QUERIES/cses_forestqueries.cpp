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

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<char>> v(n + 1, vector<char>(n + 1));
    f(i, n)
    {
        f(j, n)
        {
            cin >> v[i + 1][j + 1];
        }
    }
    vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));
    rep(i, 1, n + 1)
    {
        rep(j, 1, n + 1)
        {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (v[i][j] == '*');
        }
    }
    while (q--)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << pre[y2][x2] - pre[y1 - 1][x2] - pre[y2][x1 - 1] + pre[y1 - 1][x1 - 1] << endl;
    }
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