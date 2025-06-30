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
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int n, m;
    cin >> n >> m;
    vector<vector<char>> ar(n, vector<char>(m, 0));
    f(i, n) f(j, m) cin >> ar[i][j];
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    auto isValid = [&](int x, int y) -> bool
    {
        if (x < 0 || x > n - 1 || y < 0 || y > m - 1)
            return false;
        if (vis[x][y] == true || ar[x][y] == '#')
            return false;
        return true;
    };
    auto dfs = [&](int x, int y, auto &&dfs) -> void
    {
        vis[x][y] = true;
        f(i, 4)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny))
            {

                dfs(nx, ny, dfs);
            }
        }
    };
    int cnt = 0;
    f(i, n)
    {
        f(j, m)
        {
            if (ar[i][j] == '.' && vis[i][j] == false)
            {
                dfs(i, j, dfs);
                cnt++;
            }
        }
    }
    cout << cnt;
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