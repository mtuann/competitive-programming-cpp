// Template: tree DP rerooting
// Signal: sum of distances to all nodes is needed for every possible root.
// Assumes: the reroot transition is exactly ans[v] = ans[u] - sub_size[v] + (n - sub_size[v]).
// Exposes: TreeDistanceRerooting with add_edge(u, v), solve(root), and all_dist.
// Complexity: O(n).
// Main trap: treating this iterative sum-of-distances skeleton as a fully generic rerooting framework.
// Links:
//   Topic: topics/dp/tree-dp/README.md
//   Note: practice/ladders/dp/tree-dp/treedistances2.md

#include <iostream>
#include <vector>

using namespace std;

struct TreeDistanceRerooting {
    int n;
    vector<vector<int>> g;
    vector<int> parent;
    vector<int> order;
    vector<int> sub_size;
    vector<long long> sub_dist;
    vector<long long> all_dist;

    explicit TreeDistanceRerooting(int n)
        : n(n),
          g(n),
          parent(n, -1),
          sub_size(n, 1),
          sub_dist(n, 0),
          all_dist(n, 0) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void solve(int root = 0) {
        order.clear();
        order.reserve(n);
        vector<int> stack = {root};
        parent[root] = -1;

        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            order.push_back(u);
            for (int v : g[u]) {
                if (v == parent[u]) {
                    continue;
                }
                parent[v] = u;
                stack.push_back(v);
            }
        }

        fill(sub_size.begin(), sub_size.end(), 1);
        fill(sub_dist.begin(), sub_dist.end(), 0);
        fill(all_dist.begin(), all_dist.end(), 0);

        for (int idx = n - 1; idx >= 0; --idx) {
            int u = order[idx];
            for (int v : g[u]) {
                if (v == parent[u]) {
                    continue;
                }
                sub_size[u] += sub_size[v];
                sub_dist[u] += sub_dist[v] + sub_size[v];
            }
        }

        all_dist[root] = sub_dist[root];
        for (int u : order) {
            for (int v : g[u]) {
                if (v == parent[u]) {
                    continue;
                }
                all_dist[v] = all_dist[u] - sub_size[v] + (n - sub_size[v]);
            }
        }
    }
};

int main() {
    int n = 5;
    TreeDistanceRerooting solver(n);
    solver.add_edge(0, 1);
    solver.add_edge(0, 2);
    solver.add_edge(2, 3);
    solver.add_edge(2, 4);
    solver.solve(0);

    for (int i = 0; i < n; ++i) {
        cout << solver.all_dist[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
