// Template: Stoer-Wagner global minimum cut
// Signal: one undirected weighted graph asks for the cheapest edge cut that
// disconnects the graph, with no designated source/sink pair.
// Assumes: vertices are 0-indexed, edge weights are nonnegative long long,
// the graph is undirected, and parallel edges should be accumulated.
// Exposes: GlobalMinCut(n) with add_edge(u, v, w) and solve() returning
// {cut_value, side_mask}, where side_mask[v] is 1 on one side of an optimal cut.
// Complexity: O(n^3) with the dense Stoer-Wagner route.
// Main trap: this is global min-cut on an undirected graph, not one s-t cut;
// do not use it on directed graphs or pairwise-query cut tasks.
// Links:
//   Topic: topics/graphs/global-min-cut/README.md
//   Note: practice/ladders/graphs/global-min-cut/globalmincut.md

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

struct GlobalMinCut {
    struct Result {
        long long cut_value = 0;
        vector<char> side;
    };

    int n = 0;
    vector<vector<long long> > w;

    explicit GlobalMinCut(int n) : n(n), w(n, vector<long long>(n, 0)) {}

    void add_edge(int u, int v, long long weight) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(u != v);
        assert(weight >= 0);
        w[u][v] += weight;
        w[v][u] += weight;
    }

    Result solve() const {
        if (n <= 1) {
            return {0, vector<char>(n, 1)};
        }

        vector<vector<long long> > g = w;
        vector<vector<int> > groups(n);
        for (int i = 0; i < n; ++i) {
            groups[i].push_back(i);
        }

        long long best = numeric_limits<long long>::max();
        vector<int> best_group;
        int alive = n;

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
                assert(sel != -1);
                added[sel] = 1;

                if (step == alive - 1) {
                    if (tight[sel] < best) {
                        best = tight[sel];
                        best_group = groups[sel];
                    }
                    if (prev != -1) {
                        for (int i = 0; i < alive; ++i) {
                            if (i == prev || i == sel) {
                                continue;
                            }
                            g[prev][i] += g[sel][i];
                            g[i][prev] = g[prev][i];
                        }
                        groups[prev].insert(groups[prev].end(),
                                            groups[sel].begin(),
                                            groups[sel].end());
                        for (int i = 0; i < alive; ++i) {
                            g[i].erase(g[i].begin() + sel);
                        }
                        g.erase(g.begin() + sel);
                        groups.erase(groups.begin() + sel);
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
            best = 0;
        }
        vector<char> side(n, 0);
        for (int v : best_group) {
            side[v] = 1;
        }
        return {best, side};
    }
};

int main() {
    GlobalMinCut solver(4);
    solver.add_edge(0, 1, 3);
    solver.add_edge(1, 2, 5);
    solver.add_edge(0, 2, 4);
    solver.add_edge(2, 3, 1);

    GlobalMinCut::Result ans = solver.solve();
    cout << ans.cut_value << '\n';
    for (char bit : ans.side) {
        cout << static_cast<int>(bit) << ' ';
    }
    cout << '\n';
    return 0;
}
