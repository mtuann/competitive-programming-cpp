// Problem: Minimum Cut
// Judge: POJ 2914
// Source URL: http://poj.org/problem?id=2914
// Topic: randomized / global min-cut, Stoer-Wagner
// Idea: this is one undirected weighted global minimum cut, with no designated
// source/sink pair. Use the dense Stoer-Wagner algorithm: each phase grows a
// maximum-adjacency order, the last vertex yields one candidate cut, then the
// last two phase vertices are contracted. The minimum phase cut over all rounds
// is the global answer.

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct GlobalMinCut {
    int n;
    vector<vector<long long> > w;

    explicit GlobalMinCut(int n) : n(n), w(n, vector<long long>(n, 0)) {}

    void add_edge(int u, int v, long long weight) {
        if (u == v) {
            return;
        }
        w[u][v] += weight;
        w[v][u] += weight;
    }

    long long solve() const {
        if (n <= 1) {
            return 0;
        }

        vector<vector<long long> > g = w;
        int alive = n;
        long long best = numeric_limits<long long>::max();

        while (alive > 1) {
            vector<long long> tight(alive, 0);
            vector<char> added(alive, 0);
            int prev = -1;
            int sel = -1;

            for (int step = 0; step < alive; ++step) {
                sel = -1;
                for (int i = 0; i < alive; ++i) {
                    if (!added[i] && (sel == -1 || tight[i] > tight[sel])) {
                        sel = i;
                    }
                }

                added[sel] = 1;
                if (step == alive - 1) {
                    best = min(best, tight[sel]);
                    if (prev != -1) {
                        for (int i = 0; i < alive; ++i) {
                            if (i == prev || i == sel) {
                                continue;
                            }
                            g[prev][i] += g[sel][i];
                            g[i][prev] = g[prev][i];
                        }
                        for (int i = 0; i < alive; ++i) {
                            g[i].erase(g[i].begin() + sel);
                        }
                        g.erase(g.begin() + sel);
                        --alive;
                    }
                    break;
                }

                prev = sel;
                for (int i = 0; i < alive; ++i) {
                    if (!added[i]) {
                        tight[i] += g[sel][i];
                    }
                }
            }
        }

        if (best == numeric_limits<long long>::max()) {
            return 0;
        }
        return best;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        GlobalMinCut solver(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            solver.add_edge(u, v, w);
        }
        cout << solver.solve() << '\n';
    }
    return 0;
}
