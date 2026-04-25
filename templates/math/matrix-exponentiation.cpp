// Template: matrix exponentiation
// Signal: one fixed linear recurrence or one repeated linear transition under a modulus.
// Assumes: the transition dimension is small enough for dense O(k^3 log e) matrix powers,
// and this starter keeps one fixed MOD = 1e9+7 unless you edit the constant below.
// Exposes: Matrix(n, ident), operator*, mat_pow(base, exp), and multiply_vec(mat, vec).
// Complexity: O(k^3 log e) for mat_pow on a k x k matrix.
// Main trap: building the right recurrence but ordering the state vector incorrectly.
// Links:
//   Topic: topics/math/linear-recurrence/README.md
//   Note: practice/ladders/math/linear-recurrence/throwingdice.md

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007LL;

struct Matrix {
    int n;
    vector<vector<long long>> a;

    Matrix(int n, bool ident = false) : n(n), a(n, vector<long long>(n, 0)) {
        if (ident) {
            for (int i = 0; i < n; ++i) {
                a[i][i] = 1;
            }
        }
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(n);
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                if (a[i][k] == 0) {
                    continue;
                }
                for (int j = 0; j < n; ++j) {
                    if (other.a[k][j] == 0) {
                        continue;
                    }
                    result.a[i][j] =
                        (result.a[i][j] +
                         static_cast<long long>((static_cast<__int128>(a[i][k]) * other.a[k][j]) % MOD)) %
                        MOD;
                }
            }
        }
        return result;
    }
};

Matrix mat_pow(Matrix base, long long exp) {
    Matrix result(base.n, true);
    while (exp > 0) {
        if (exp & 1LL) {
            result = result * base;
        }
        base = base * base;
        exp >>= 1LL;
    }
    return result;
}

vector<long long> multiply_vec(const Matrix& mat, const vector<long long>& vec) {
    vector<long long> result(mat.n, 0);
    for (int i = 0; i < mat.n; ++i) {
        for (int j = 0; j < mat.n; ++j) {
            if (mat.a[i][j] == 0 || vec[j] == 0) {
                continue;
            }
            result[i] =
                (result[i] +
                 static_cast<long long>((static_cast<__int128>(mat.a[i][j]) * vec[j]) % MOD)) %
                MOD;
        }
    }
    return result;
}

int main() {
    Matrix fib(2);
    fib.a[0][0] = 1;
    fib.a[0][1] = 1;
    fib.a[1][0] = 1;
    fib.a[1][1] = 0;

    vector<long long> state = {1, 0};  // [F1, F0]
    vector<long long> ans = multiply_vec(mat_pow(fib, 9), state);  // [F10, F9]
    cout << ans[0] << '\n';
    return 0;
}
