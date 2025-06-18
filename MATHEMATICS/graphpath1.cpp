#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(i, a) for (int i = 0; i < a; i++)
const int MOD = 1e9 + 7;
const long long MOD2 = static_cast<long long>(MOD) * MOD;

struct Matrix
{
    vector<vector<int>> mat;
    int n_rows, n_cols;

    Matrix() {}

    Matrix(vector<vector<int>> values) : mat(values), n_rows(values.size()), n_cols(values[0].size()) {}

    static Matrix identity_matrix(int n)
    {
        vector<vector<int>> values(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            values[i][i] = 1;
        return Matrix(values);
    }

    Matrix operator*(const Matrix &other) const
    {
        int n = n_rows, m = other.n_cols;
        vector<vector<int>> result(n_rows, vector<int>(other.n_cols, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                long long tmp = 0;
                for (int k = 0; k < n_cols; k++)
                {
                    tmp += mat[i][k] * 1ll * other.mat[k][j];
                    while (tmp >= MOD2)
                        tmp -= MOD2;
                }
                result[i][j] = tmp % MOD;
            }

        return move(Matrix(move(result)));
    }

    inline bool is_square() const
    {
        return n_rows == n_cols;
    }
};
Matrix pw(Matrix a, int p)
{
    Matrix result = Matrix::identity_matrix(a.n_cols);
    while (p > 0)
    {
        if (p & 1)
            result = a * result;
        a = a * a;
        p >>= 1;
    }
    return result;
}
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> x(n, vector<int>(n, 0));
    f(i, m)
    {
        int a, b;
        cin >> a >> b;
        x[a - 1][b - 1]++;
    }
    cout << pw(Matrix(x), k).mat[0][n - 1] << endl;
}
int main()
{
    solve();
}