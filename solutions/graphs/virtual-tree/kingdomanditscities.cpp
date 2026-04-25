// Problem: Kingdom and its Cities
// Judge: Codeforces
// Source URL: https://codeforces.com/problemset/problem/613/D
// Topic: virtual tree, marked subset DP, pairwise separation on trees
// Idea: for each query, build the virtual tree on important vertices plus
// needed LCAs, then run a two-state DP where dp0 means no important component
// leaves upward through this node and dp1 means exactly one does. A compressed
// edge can be sealed with cost 1 iff its represented path contains some
// deletable non-important city.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct VirtualTreeBuilder {
    struct Result {
        vector<int> nodes;
        vector<int> parent;
        vector<int> depth_from_parent;
        vector<vector<int>> children;
    };

    int n = 0;
    int logn = 0;
    int root = 0;
    vector<vector<int>> tree;
    vector<vector<int>> up;
    vector<int> depth;
    vector<int> tin;
    vector<int> tout;

    VirtualTreeBuilder(const vector<vector<int>>& tree, int root = 0)
        : n(static_cast<int>(tree.size())),
          root(root),
          tree(tree),
          depth(n, 0),
          tin(n, 0),
          tout(n, 0) {
        while ((1 << logn) <= max(1, n)) {
            ++logn;
        }
        up.assign(logn, vector<int>(n, root));
        build_lca();
    }

    bool is_ancestor(int u, int v) const {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int lca(int u, int v) const {
        if (is_ancestor(u, v)) {
            return u;
        }
        if (is_ancestor(v, u)) {
            return v;
        }
        int x = u;
        for (int j = logn - 1; j >= 0; --j) {
            int candidate = up[j][x];
            if (!is_ancestor(candidate, v)) {
                x = candidate;
            }
        }
        return up[0][x];
    }

    Result build(vector<int> vertices) const {
        Result result;
        sort(vertices.begin(), vertices.end(), [&](int a, int b) {
            return tin[a] < tin[b];
        });
        vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());

        int initial = static_cast<int>(vertices.size());
        vertices.reserve(initial * 2);
        for (int i = 0; i + 1 < initial; ++i) {
            vertices.push_back(lca(vertices[i], vertices[i + 1]));
        }

        sort(vertices.begin(), vertices.end(), [&](int a, int b) {
            return tin[a] < tin[b];
        });
        vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());

        int m = static_cast<int>(vertices.size());
        result.nodes = vertices;
        result.parent.assign(m, -1);
        result.depth_from_parent.assign(m, 0);
        result.children.assign(m, {});

        vector<int> stack = {0};
        for (int i = 1; i < m; ++i) {
            while (!is_ancestor(vertices[stack.back()], vertices[i])) {
                stack.pop_back();
            }
            int p = stack.back();
            result.parent[i] = p;
            result.depth_from_parent[i] = depth[vertices[i]] - depth[vertices[p]];
            result.children[p].push_back(i);
            stack.push_back(i);
        }
        return result;
    }

private:
    void build_lca() {
        int timer = 0;
        vector<int> parent(n, root);
        vector<pair<int, int>> stack;
        stack.reserve(2 * n);
        stack.push_back({root, 0});
        parent[root] = root;

        while (!stack.empty()) {
            auto [u, state] = stack.back();
            stack.pop_back();
            if (state == 0) {
                tin[u] = timer++;
                stack.push_back({u, 1});
                for (int i = static_cast<int>(tree[u].size()) - 1; i >= 0; --i) {
                    int v = tree[u][i];
                    if (v == parent[u]) {
                        continue;
                    }
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    stack.push_back({v, 0});
                }
            } else {
                tout[u] = timer;
            }
        }

        for (int v = 0; v < n; ++v) {
            up[0][v] = parent[v];
        }
        for (int j = 1; j < logn; ++j) {
            for (int v = 0; v < n; ++v) {
                up[j][v] = up[j - 1][up[j - 1][v]];
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    VirtualTreeBuilder builder(tree, 0);

    int q;
    cin >> q;

    const int INF = 1'000'000'000;
    vector<char> important(n, false);

    auto add_cost = [&](int a, int b) {
        if (a >= INF || b >= INF) {
            return INF;
        }
        return min(INF, a + b);
    };

    while (q--) {
        int k;
        cin >> k;
        vector<int> marked(k);
        for (int i = 0; i < k; ++i) {
            cin >> marked[i];
            --marked[i];
            important[marked[i]] = true;
        }

        auto vt = builder.build(marked);
        int m = static_cast<int>(vt.nodes.size());
        vector<int> dp0(m, INF), dp1(m, INF);

        for (int i = m - 1; i >= 0; --i) {
            bool key = important[vt.nodes[i]];
            int keep0 = key ? INF : 0;
            int keep1 = key ? 0 : INF;
            int erase_u = key ? INF : 1;

            for (int child : vt.children[i]) {
                int cut_cost = 1;
                if (vt.depth_from_parent[child] == 1 && important[vt.nodes[child]]) {
                    cut_cost = INF;
                }

                int close_child = min(dp0[child], add_cost(dp1[child], cut_cost));
                int keep_child = dp1[child];

                int next0 = add_cost(keep0, close_child);
                int next1 = min(add_cost(keep1, close_child), add_cost(keep0, keep_child));

                keep0 = next0;
                keep1 = next1;

                if (!key) {
                    erase_u = add_cost(erase_u, min(dp0[child], dp1[child]));
                }
            }

            dp0[i] = key ? keep0 : min(keep0, erase_u);
            dp1[i] = keep1;
        }

        int answer = min(dp0[0], dp1[0]);
        cout << (answer >= INF ? -1 : answer) << '\n';

        for (int u : marked) {
            important[u] = false;
        }
    }
    return 0;
}
