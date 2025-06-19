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
vector<ll> tree[MAXN];

void dfs(ll src, ll par, vector<ll> &ans)
{
    ll subords = 0;
    for (auto child : tree[src])
    {
        if (child != par)
        {
            dfs(child, src, ans);
            subords += (1 + ans[child]);
        }
    }
    ans[src] = subords;
}
void solve()
{
    ll n;
    cin >> n;
    vi ans(n + 1);
    rep(i, 2, n + 1)
    {
        ll x;
        cin >> x;
        tree[x].pb(i);
        tree[i].pb(x);
    }
    dfs(1, 0, ans);
    for (int i = 1; i < n + 1; i++)
    {
        cout << ans[i] << ' ';
    }
}
int main()
{
    solve();
    return 0;
}