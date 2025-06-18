#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const ll MAXN = 3e5;
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rrep(i, a, b) for (ll i = a; i >= b; i--)
#define f(i, n) for (ll i = 0; i < n; ++i)
#define input(v, n)            \
    for (ll i = 0; i < n; i++) \
    {                          \
        cin >> v[i];           \
    }
ll i;
#define loop(n) for (i = 0; i < n; i++)
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define endl '\n'
#define all(v) (v).begin(), v.end()
#define vi vector<ll>
#define pii pair<ll, ll>
#define vpi vector<pii>
#define vb vector<bool>
#define pb push_back
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbgv(v)             \
    cerr << #v << " = [ ";  \
    for (auto &ele : v)     \
        cerr << ele << " "; \
    cerr << "]" << endl;
ll MOD = 1e9 + 7;
ll MOD2 = 998244353;
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);

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

    fastio;
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
}