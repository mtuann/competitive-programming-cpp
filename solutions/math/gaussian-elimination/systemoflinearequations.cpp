#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static constexpr long long MOD = 1000000007LL;

long long norm_mod(long long x) {
    x %= MOD;
    if (x < 0) {
        x += MOD;
    }
    return x;
}

long long pow_mod(long long a, long long e) {
    long long result = 1 % MOD;
    a = norm_mod(a);
    while (e > 0) {
        if (e & 1LL) {
            result = static_cast<long long>((static_cast<__int128>(result) * a) % MOD);
        }
        a = static_cast<long long>((static_cast<__int128>(a) * a) % MOD);
        e >>= 1LL;
    }
    return result;
}

struct GaussResult {
    int status;  // 0 = no solution, 1 = unique, 2 = multiple
    vector<long long> x;
};

GaussResult gauss_mod_prime(vector<vector<long long>> a) {
    const int n = static_cast<int>(a.size());
    const int m = static_cast<int>(a[0].size()) - 1;
    vector<int> where(m, -1);
    int row = 0;

    for (int col = 0; col < m && row < n; ++col) {
        int sel = row;
        while (sel < n && norm_mod(a[sel][col]) == 0) {
            ++sel;
        }
        if (sel == n) {
            continue;
        }

        swap(a[sel], a[row]);
        long long inv = pow_mod(a[row][col], MOD - 2);
        for (int j = col; j <= m; ++j) {
            a[row][j] = static_cast<long long>((static_cast<__int128>(norm_mod(a[row][j])) * inv) % MOD);
        }

        for (int i = 0; i < n; ++i) {
            if (i == row) {
                continue;
            }
            long long factor = norm_mod(a[i][col]);
            if (factor == 0) {
                continue;
            }
            for (int j = col; j <= m; ++j) {
                long long delta = static_cast<long long>(
                    (static_cast<__int128>(factor) * norm_mod(a[row][j])) % MOD
                );
                a[i][j] = norm_mod(a[i][j] - delta);
            }
        }

        where[col] = row;
        ++row;
    }

    for (int i = 0; i < n; ++i) {
        bool all_zero = true;
        for (int j = 0; j < m; ++j) {
            if (norm_mod(a[i][j]) != 0) {
                all_zero = false;
                break;
            }
        }
        if (all_zero && norm_mod(a[i][m]) != 0) {
            return {0, {}};
        }
    }

    vector<long long> x(m, 0);
    for (int col = 0; col < m; ++col) {
        if (where[col] != -1) {
            x[col] = norm_mod(a[where[col]][m]);
        }
    }

    int status = 1;
    for (int col = 0; col < m; ++col) {
        if (where[col] == -1) {
            status = 2;
            break;
        }
    }
    return {status, x};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    GaussResult res = gauss_mod_prime(a);
    if (res.status == 0) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < m; ++i) {
        if (i) {
            cout << ' ';
        }
        cout << res.x[i];
    }
    cout << '\n';
    return 0;
}
