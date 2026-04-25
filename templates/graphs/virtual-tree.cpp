// Template: Virtual tree / auxiliary tree
// Signal: one static rooted tree gets many queries, each query marks a small
// subset of vertices, and the real work should run on the compressed union of
// marked paths instead of on the full tree.
// Assumes: the original graph is a tree, vertices are 0-indexed, the tree is
// rooted once for preprocessing, and one query only needs nodes, parent
// relation, children lists, and original depth differences on compressed
// edges.
// Exposes: VirtualTreeBuilder(tree, root) with lca(u, v), is_ancestor(u, v),
// and build(vertices) -> {nodes, parent, depth_from_parent, children}.
// Complexity: preprocessing O(n log n), one build O(k log n) for k query
// vertices including sorting and LCA calls.
// Main trap: forgetting to sort by tin, add LCAs of consecutive vertices, and
// deduplicate before the stack build.
// Links:
//   Topic: topics/graphs/virtual-tree/README.md
//   Note: practice/ladders/graphs/virtual-tree/kingdomanditscities.md

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
        if (vertices.empty()) {
            return result;
        }

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
    vector<vector<int>> tree(6);
    auto add_edge = [&](int u, int v) {
        tree[u].push_back(v);
        tree[v].push_back(u);
    };
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 3);
    add_edge(1, 4);
    add_edge(2, 5);

    VirtualTreeBuilder builder(tree, 0);
    auto result = builder.build({3, 4, 5});

    cout << result.nodes.size() << '\n';
    for (int i = 0; i < static_cast<int>(result.nodes.size()); ++i) {
        cout << result.nodes[i] << ' ' << result.parent[i] << ' '
             << result.depth_from_parent[i] << '\n';
    }
    return 0;
}

