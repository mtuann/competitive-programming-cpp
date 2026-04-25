// Template: Gaussian elimination over a prime modulus
// Signal: solve one linear system A x = b modulo one prime and recover any valid assignment.
// Assumes: mod is prime, every matrix entry is interpreted modulo mod, and dense O(min(n, m) * n * m) elimination is affordable.
// Exposes: pow_mod(a, e, mod), struct GaussResult, and gauss_mod_prime(a, mod).
// Complexity: O(min(n, m) * n * m).
// Main trap: treating every nonzero pivot as invertible under a composite modulus.
// Links:
//   Topic: topics/math/gaussian-elimination/README.md
//   Note: practice/ladders/math/gaussian-elimination/systemoflinearequations.md

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

long long norm_mod(long long x, long long mod) {
    x %= mod;
    if (x < 0) {
        x += mod;
    }
    return x;
}

long long pow_mod(long long a, long long e, long long mod) {
    long long result = 1 % mod;
    a = norm_mod(a, mod);
    while (e > 0) {
        if (e & 1LL) {
            result = static_cast<long long>((static_cast<__int128>(result) * a) % mod);
        }
        a = static_cast<long long>((static_cast<__int128>(a) * a) % mod);
        e >>= 1LL;
    }
    return result;
}

struct GaussResult {
    int status;  // 0 = no solution, 1 = unique, 2 = multiple
    int rank;
    vector<long long> x;
    vector<int> where;
};

GaussResult gauss_mod_prime(vector<vector<long long>> a, long long mod) {
    const int n = static_cast<int>(a.size());
    const int m = static_cast<int>(a[0].size()) - 1;
    vector<int> where(m, -1);
    int row = 0;

    for (int col = 0; col < m && row < n; ++col) {
        int sel = row;
        while (sel < n && norm_mod(a[sel][col], mod) == 0) {
            ++sel;
        }
        if (sel == n) {
            continue;
        }

        swap(a[sel], a[row]);
        long long inv = pow_mod(a[row][col], mod - 2, mod);
        for (int j = col; j <= m; ++j) {
            a[row][j] = static_cast<long long>((static_cast<__int128>(norm_mod(a[row][j], mod)) * inv) % mod);
        }

        for (int i = 0; i < n; ++i) {
            if (i == row) {
                continue;
            }
            long long factor = norm_mod(a[i][col], mod);
            if (factor == 0) {
                continue;
            }
            for (int j = col; j <= m; ++j) {
                long long delta = static_cast<long long>(
                    (static_cast<__int128>(factor) * norm_mod(a[row][j], mod)) % mod
                );
                a[i][j] = norm_mod(a[i][j] - delta, mod);
            }
        }

        where[col] = row;
        ++row;
    }

    for (int i = 0; i < n; ++i) {
        bool all_zero = true;
        for (int j = 0; j < m; ++j) {
            if (norm_mod(a[i][j], mod) != 0) {
                all_zero = false;
                break;
            }
        }
        if (all_zero && norm_mod(a[i][m], mod) != 0) {
            return {0, row, {}, where};
        }
    }

    vector<long long> x(m, 0);
    for (int col = 0; col < m; ++col) {
        if (where[col] != -1) {
            x[col] = norm_mod(a[where[col]][m], mod);
        }
    }

    int status = 1;
    for (int col = 0; col < m; ++col) {
        if (where[col] == -1) {
            status = 2;
            break;
        }
    }
    return {status, row, x, where};
}

int main() {
    const long long MOD = 1000000007LL;
    vector<vector<long long>> augmented = {
        {1, 1, 3},
        {2, 1, 4},
    };
    GaussResult res = gauss_mod_prime(augmented, MOD);
    if (res.status == 0) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < static_cast<int>(res.x.size()); ++i) {
        if (i) {
            cout << ' ';
        }
        cout << res.x[i];
    }
    cout << '\n';
    return 0;
}
