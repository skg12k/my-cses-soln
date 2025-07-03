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
struct mint
{
    int v;
    mint() : v(0) {}
    mint(int x) { v = x >= 0 ? x % MOD : x + (-x + MOD - 1) / MOD * MOD; }
    friend ostream &operator<<(ostream &stream, const mint &x)
    {
        stream << x.v;
        return stream;
    }
    friend istream &operator>>(istream &stream, mint &val)
    {
        int x;
        stream >> x;
        val.v = x >= 0 ? x % MOD : x + (-x + MOD - 1) / MOD * MOD;
        return stream;
    }
    operator int() const { return v; }
    mint &operator++()
    {
        if (++v >= MOD)
            v -= MOD;
        return *this;
    }
    mint &operator--()
    {
        if (--v < 0)
            v += MOD;
        return *this;
    }
    mint &operator+=(const mint &y)
    {
        v = v + y.v - ((v + y.v) >= MOD ? MOD : 0);
        return *this;
    }
    mint operator+(const mint &y) const
    {
        mint x = *this;
        return x += y;
    }
    mint &operator-=(const mint &y)
    {
        v = v - y.v + (v - y.v < 0 ? MOD : 0);
        return *this;
    }
    mint operator-(const mint &y) const
    {
        mint x = *this;
        return x -= y;
    }
    mint &operator*=(const mint &y)
    {
        v = ((long long)v * y.v) % MOD;
        return *this;
    }
    mint operator*(const mint &y) const
    {
        mint x = *this;
        return x *= y;
    }
    mint &operator%=(const mint &y)
    {
        if (y.v)
            v %= y.v;
        return *this;
    }
    mint operator%(const mint &y) const
    {
        mint x = *this;
        return x %= y;
    }
    mint &operator/=(const mint &y) { return *this *= ModInverse(y.v); }
    mint operator/(const mint &y) const { return *this * ModInverse(y.v); }
    mint &operator^=(const mint &y)
    {
        *this = this->Pow(y);
        return *this;
    }
    mint Pow(int y) const
    {
        mint r = 1, x = v;
        for (y <<= 1; y >>= 1; x = x * x)
            if (y & 1)
                r = r * x;
        return r;
    }
    mint ModInverse(int a) const { return mint(a) ^ (MOD - 2); }
    friend mint operator+(const mint &a, long long b) { return a + mint(b); }
    friend mint operator+(long long a, const mint &b) { return mint(a) + b; }
    friend mint operator+(const mint &a, int32_t b) { return a + mint(b); }
    friend mint operator+(int32_t a, const mint &b) { return mint(a) + b; }
    friend mint operator-(const mint &a, long long b) { return a - mint(b); }
    friend mint operator-(long long a, const mint &b) { return mint(a) - b; }
    friend mint operator-(const mint &a, int32_t b) { return a - mint(b); }
    friend mint operator-(int32_t a, const mint &b) { return mint(a) - b; }
    friend mint operator*(const mint &a, long long b) { return a * mint(b); }
    friend mint operator*(long long a, const mint &b) { return mint(a) * b; }
    friend mint operator*(const mint &a, int32_t b) { return a * mint(b); }
    friend mint operator*(int32_t a, const mint &b) { return mint(a) * b; }
    friend mint operator/(const mint &a, int32_t b) { return a / mint(b); }
    friend mint operator/(int32_t a, const mint &b) { return mint(a) / b; }
    friend mint operator/(const mint &a, long long b) { return a / mint(b); }
    friend mint operator/(long long a, const mint &b) { return mint(a) / b; }
    friend mint operator^(const mint &a, long long b) { return a.Pow(b); }
    friend mint operator^(long long a, const mint &b) { return mint(a).Pow(b); }
    friend mint operator^(const mint &a, int32_t b) { return a.Pow(b); }
    friend mint operator^(int32_t a, const mint &b) { return mint(a).Pow(b); }
    friend mint operator^(const mint &a, const mint &b) { return a.Pow(b); }
    bool operator==(const mint &y) const { return v == y.v; }
    bool operator==(int32_t y) const { return v == y; }
    bool operator==(long long y) const { return v == y; }
    bool operator!=(const mint &y) const { return v != y.v; }
    bool operator!=(int32_t y) const { return v != y; }
    bool operator!=(long long y) const { return v != y; }
    bool operator>(const mint &y) const { return v > y.v; }
    bool operator>(int32_t y) const { return v > y; }
    bool operator>(long long y) const { return v > y; }
    bool operator>=(const mint &y) const { return v >= y.v; }
    bool operator>=(int32_t y) const { return v >= y; }
    bool operator>=(long long y) const { return v >= y; }
    bool operator<(const mint &y) const { return v < y.v; }
    bool operator<(int32_t y) const { return v < y; }
    bool operator<(long long y) const { return v < y; }
    bool operator<=(const mint &y) const { return v <= y.v; }
    bool operator<=(int32_t y) const { return v <= y; }
    bool operator<=(long long y) const { return v <= y; }

    mint pow(long long e) const
    {
        mint base = *this, res = 1;
        while (e)
        {
            if (e & 1)
                res *= base;
            base *= base;
            e >>= 1;
        }
        return res;
    }
    mint inv() const { return this->pow(MOD - 2); }
};
void solve()
{
    mint n, k;
    cin >> n >> k;
    vector<vector<mint>> dp(n, vector<mint>(k + 1, 0)); // dp[i][j] -> till i kid j candies
    vector<mint> a(n);
    f(i, n)
    {
        cin >> a[i];
    }

    for (mint i = 0; i <= a[0]; i += 1)
    {
        dp[0][i] = 1;
    }

    for (mint i = 1; i < n; i += 1)
    {
        vector<mint> pre(k + 1);
        pre[0] = dp[i - 1][0];
        for (mint j = 1; j < k + 1; j += 1)
        {
            // dp[i][j]
            pre[j] = (pre[j - 1] + dp[i - 1][j]);
        }
        for (mint j = 0; j <= k; j += 1)
        {
            if (j >= a[i] + 1)
                dp[i][j] = (pre[j] - pre[j - a[i] - 1]);
            else
                dp[i][j] = pre[j];
        }
    }
    cout << dp[n - 1][k];
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