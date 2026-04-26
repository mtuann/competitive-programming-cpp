// Template: Hungarian / assignment problem
// Signal: dense square cost matrix, one row per column, minimum total assignment cost.
// Assumes: the matrix is square and a perfect assignment is required.
// Exposes: hungarian(cost) -> {minimum cost, assignment}, where assignment[i] is the chosen column for row i.
// Complexity: O(n^3) for an n x n matrix.
// Main trap: using this when capacities, sparse forbidden edges, or richer transport structure make min-cost flow the cleaner model.
// Links:
//   Topic: topics/graphs/hungarian-assignment/README.md
//   Note: practice/ladders/graphs/hungarian-assignment/taskassignment.md

#include <cassert>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

using namespace std;

pair<long long, vector<int>> hungarian(const vector<vector<long long>> &cost) {
    int n = static_cast<int>(cost.size());
    if (n == 0) return {0, {}};
    for (const auto &row : cost) {
        assert(static_cast<int>(row.size()) == n);
    }

    vector<long long> u(n + 1), v(n + 1);
    vector<int> p(n + 1), way(n + 1);

    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<long long> minv(n + 1, numeric_limits<long long>::max() / 4);
        vector<char> used(n + 1, false);
        do {
            used[j0] = true;
            int i0 = p[j0];
            long long delta = numeric_limits<long long>::max() / 4;
            int j1 = 0;
            for (int j = 1; j <= n; ++j) {
                if (used[j]) continue;
                long long cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                if (cur < minv[j]) {
                    minv[j] = cur;
                    way[j] = j0;
                }
                if (minv[j] < delta) {
                    delta = minv[j];
                    j1 = j;
                }
            }
            for (int j = 0; j <= n; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }

    vector<int> assignment(n, -1);
    for (int j = 1; j <= n; ++j) {
        assignment[p[j] - 1] = j - 1;
    }
    return {-v[0], assignment};
}

int main() {
    vector<vector<long long>> cost = {
        {4, 1, 3},
        {2, 0, 5},
        {3, 2, 2},
    };
    auto [best, assignment] = hungarian(cost);
    cout << best << '\n';
    for (int j : assignment) {
        cout << j << ' ';
    }
    cout << '\n';
    return 0;
}
