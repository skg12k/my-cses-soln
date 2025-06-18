#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
#define dbgv(v)             \
    cerr << #v << " = [ ";  \
    for (auto &ele : v)     \
        cerr << ele << " "; \
    cerr << "]" << endl;

// backtracking check

const long long MAXN = 1e6;
void solve()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];
    int dp[N + 1][M + 1];
    for (int i = 0; i <= N; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= M; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max({
                    dp[i - 1][j],
                    dp[i][j - 1],
                });
            }
        }
    }

    cout << dp[N][M] << '\n';

    int i = N, j = M;
    vector<int> ans;
    while (i > 0 && j > 0)
    {
        if (A[i - 1] == B[j - 1])
        {
            ans.push_back(A[i - 1]);
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(ans.begin(), ans.end());
    for (int x : ans)
        cout << x << " ";
    cout << '\n';
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