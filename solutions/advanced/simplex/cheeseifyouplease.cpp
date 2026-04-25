#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

using namespace std;

using ld = long double;

static constexpr ld SIMPLEX_EPS = 1e-12L;
static constexpr ld SIMPLEX_INF = numeric_limits<ld>::infinity();

enum class SimplexStatus {
    OPTIMAL,
    INFEASIBLE,
    UNBOUNDED,
};

struct SimplexResult {
    SimplexStatus status = SimplexStatus::INFEASIBLE;
    ld optimum = 0;
    vector<ld> x;
};

struct SimplexSolver {
    int m = 0;
    int n = 0;
    vector<int> nonbasic;
    vector<int> basic;
    vector<vector<ld>> tableau;

    SimplexSolver(const vector<vector<ld>>& A, const vector<ld>& b, const vector<ld>& c)
        : m(static_cast<int>(b.size())),
          n(static_cast<int>(c.size())),
          nonbasic(n + 1),
          basic(m),
          tableau(m + 2, vector<ld>(n + 2, 0)) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                tableau[i][j] = A[i][j];
            }
            basic[i] = n + i;
            tableau[i][n] = -1;
            tableau[i][n + 1] = b[i];
        }
        for (int j = 0; j < n; ++j) {
            nonbasic[j] = j;
            tableau[m][j] = -c[j];
        }
        nonbasic[n] = -1;
        tableau[m + 1][n] = 1;
    }

    void pivot(int row, int col) {
        ld* pivot_row = tableau[row].data();
        ld inv = 1.0L / pivot_row[col];

        for (int i = 0; i < m + 2; ++i) {
            if (i == row || fabsl(tableau[i][col]) <= SIMPLEX_EPS) {
                continue;
            }
            ld* current = tableau[i].data();
            ld factor = current[col] * inv;
            for (int j = 0; j < n + 2; ++j) {
                current[j] -= pivot_row[j] * factor;
            }
            current[col] = pivot_row[col] * factor;
        }

        for (int j = 0; j < n + 2; ++j) {
            if (j != col) {
                tableau[row][j] *= inv;
            }
        }
        for (int i = 0; i < m + 2; ++i) {
            if (i != row) {
                tableau[i][col] *= -inv;
            }
        }
        tableau[row][col] = inv;
        swap(basic[row], nonbasic[col]);
    }

    int choose_entering(int objective_row, int phase) const {
        int chosen = -1;
        for (int j = 0; j <= n; ++j) {
            if (nonbasic[j] == -phase) {
                continue;
            }
            if (chosen == -1 ||
                make_pair(tableau[objective_row][j], nonbasic[j]) <
                    make_pair(tableau[objective_row][chosen], nonbasic[chosen])) {
                chosen = j;
            }
        }
        return chosen;
    }

    int choose_cleanup_col(int row) const {
        int chosen = 0;
        for (int j = 1; j <= n; ++j) {
            if (make_pair(tableau[row][j], nonbasic[j]) <
                make_pair(tableau[row][chosen], nonbasic[chosen])) {
                chosen = j;
            }
        }
        return chosen;
    }

    bool run_simplex(int phase) {
        int objective_row = m + phase - 1;
        while (true) {
            int col = choose_entering(objective_row, phase);
            if (col == -1 || tableau[objective_row][col] >= -SIMPLEX_EPS) {
                return true;
            }

            int row = -1;
            for (int i = 0; i < m; ++i) {
                if (tableau[i][col] <= SIMPLEX_EPS) {
                    continue;
                }
                if (row == -1 ||
                    make_pair(tableau[i][n + 1] / tableau[i][col], basic[i]) <
                        make_pair(tableau[row][n + 1] / tableau[row][col], basic[row])) {
                    row = i;
                }
            }
            if (row == -1) {
                return false;
            }
            pivot(row, col);
        }
    }

    SimplexResult solve() {
        SimplexResult result;
        result.x.assign(n, 0);

        if (m == 0) {
            for (int j = 0; j < n; ++j) {
                if (-tableau[m][j] > SIMPLEX_EPS) {
                    result.status = SimplexStatus::UNBOUNDED;
                    result.optimum = SIMPLEX_INF;
                    return result;
                }
            }
            result.status = SimplexStatus::OPTIMAL;
            result.optimum = 0;
            return result;
        }

        int row = 0;
        for (int i = 1; i < m; ++i) {
            if (tableau[i][n + 1] < tableau[row][n + 1]) {
                row = i;
            }
        }

        if (tableau[row][n + 1] < -SIMPLEX_EPS) {
            pivot(row, n);
            if (!run_simplex(2) || tableau[m + 1][n + 1] < -SIMPLEX_EPS) {
                result.status = SimplexStatus::INFEASIBLE;
                result.optimum = -SIMPLEX_INF;
                return result;
            }
            for (int i = 0; i < m; ++i) {
                if (basic[i] == -1) {
                    pivot(i, choose_cleanup_col(i));
                }
            }
        }

        if (!run_simplex(1)) {
            for (int i = 0; i < m; ++i) {
                if (basic[i] < n) {
                    result.x[basic[i]] = tableau[i][n + 1];
                }
            }
            result.status = SimplexStatus::UNBOUNDED;
            result.optimum = SIMPLEX_INF;
            return result;
        }

        for (int i = 0; i < m; ++i) {
            if (basic[i] < n) {
                result.x[basic[i]] = tableau[i][n + 1];
            }
        }
        result.status = SimplexStatus::OPTIMAL;
        result.optimum = tableau[m][n + 1];
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ld> stock(n);
    for (int i = 0; i < n; ++i) {
        cin >> stock[i];
    }

    vector<vector<ld>> A(n, vector<ld>(m, 0));
    vector<ld> profit(m);

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            ld percent;
            cin >> percent;
            A[i][j] = percent / 100.0L;
        }
        cin >> profit[j];
    }

    SimplexResult res = SimplexSolver(A, stock, profit).solve();

    ld answer = 0;
    if (res.status == SimplexStatus::OPTIMAL && isfinite(static_cast<double>(res.optimum))) {
        answer = res.optimum;
    }
    if (fabsl(answer) < 1e-11L) {
        answer = 0;
    }

    cout << fixed << setprecision(2) << (answer + 1e-12L) << '\n';
    return 0;
}
