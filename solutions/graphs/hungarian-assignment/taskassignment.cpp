#include <iostream>
#include <limits>
#include <vector>

using namespace std;

pair<long long, vector<int>> hungarian(const vector<vector<long long>> &cost) {
    int n = static_cast<int>(cost.size());
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<long long>> cost(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    auto [best, assignment] = hungarian(cost);
    cout << best << '\n';
    for (int i = 0; i < n; ++i) {
        cout << (i + 1) << ' ' << (assignment[i] + 1) << '\n';
    }
    return 0;
}
