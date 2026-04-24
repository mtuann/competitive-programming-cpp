// Template: LCA by binary lifting
// Signal: many static ancestor or LCA queries on one rooted tree.
// Assumes: the tree is fixed after preprocessing and parent jumps are enough for the query family.
// Exposes: LCA with add_edge(u, v), build(root), and query(a, b).
// Complexity: O(n log n) build, O(log n) per query.
// Main trap: forgetting to build from the intended root, then trusting every depth/ancestor relation afterward.
// Links:
//   Topic: topics/graphs/lca/README.md
//   Note: practice/ladders/graphs/lca/companyqueries2.md

#include <iostream>
#include <vector>

using namespace std;

struct LCA {
    int n, logn;
    vector<int> depth;
    vector<vector<int>> up;
    vector<vector<int>> g;

    explicit LCA(int n) : n(n), logn(1), depth(n, 0), g(n) {
        while ((1 << logn) <= n) ++logn;
        up.assign(logn, vector<int>(n, 0));
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void dfs(int u, int p) {
        up[0][u] = p;
        for (int k = 1; k < logn; ++k) {
            up[k][u] = up[k - 1][up[k - 1][u]];
        }
        for (int v : g[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    void build(int root) {
        depth[root] = 0;
        dfs(root, root);
    }

    int lift(int u, int dist) const {
        for (int k = 0; k < logn; ++k) {
            if (dist & (1 << k)) {
                u = up[k][u];
            }
        }
        return u;
    }

    int query(int a, int b) const {
        if (depth[a] < depth[b]) swap(a, b);
        a = lift(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (int k = logn - 1; k >= 0; --k) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }
        return up[0][a];
    }
};

int main() {
    LCA lca(7);
    lca.add_edge(0, 1);
    lca.add_edge(0, 2);
    lca.add_edge(1, 3);
    lca.add_edge(1, 4);
    lca.add_edge(2, 5);
    lca.add_edge(2, 6);
    lca.build(0);
    cout << lca.query(3, 4) << '\n';
    cout << lca.query(3, 6) << '\n';
    return 0;
}
