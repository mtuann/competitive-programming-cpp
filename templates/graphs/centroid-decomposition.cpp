// Template: centroid decomposition
// Signal: static tree problems where each node/query only needs O(log n)
// centroid ancestors, or where paths are processed by “through this centroid”
// versus “inside one child component”.
// Assumes: the tree is static, nodes are 0-indexed, and you want a reusable
// centroid tree plus per-node centroid ancestors/distances.
// Exposes: CentroidDecomposition with add_edge(u, v), build(root), centroid_parent,
// centroid_depth, centroid_ancestors(u), and centroid_distances(u) in nearest-centroid-first order.
// Complexity: O(n log n) build, and ancestor walks are O(log n) per node/query.
// Main trap: confusing the centroid tree with the original tree or erasing edges
// instead of guarding recursion with removed[].
// Links:
//   Topic: topics/graphs/centroid-decomposition/README.md
//   Note: practice/ladders/graphs/centroid-decomposition/cielthecommander.md

#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct CentroidDecomposition {
    int n;
    vector<vector<int>> graph;
    vector<int> subtree_size;
    vector<int> parent_local;
    vector<int> centroid_parent;
    vector<int> centroid_depth;
    vector<char> removed;
    vector<vector<int>> anc;
    vector<vector<int>> dist;

    explicit CentroidDecomposition(int n)
        : n(n),
          graph(n),
          subtree_size(n, 0),
          parent_local(n, -1),
          centroid_parent(n, -1),
          centroid_depth(n, -1),
          removed(n, false),
          anc(n),
          dist(n) {}

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void build(int root = 0) {
        fill(removed.begin(), removed.end(), false);
        fill(centroid_parent.begin(), centroid_parent.end(), -1);
        fill(centroid_depth.begin(), centroid_depth.end(), -1);
        for (int u = 0; u < n; ++u) {
            anc[u].clear();
            dist[u].clear();
        }
        decompose(root, -1, 0);
        for (int u = 0; u < n; ++u) {
            reverse(anc[u].begin(), anc[u].end());
            reverse(dist[u].begin(), dist[u].end());
        }
    }

    const vector<int>& centroid_ancestors(int u) const {
        return anc[u];
    }

    const vector<int>& centroid_distances(int u) const {
        return dist[u];
    }

private:
    int find_centroid(int entry, vector<int>& nodes) {
        nodes.clear();
        vector<int> order;
        vector<pair<int, int>> stack = {{entry, -1}};

        while (!stack.empty()) {
            auto [u, p] = stack.back();
            stack.pop_back();
            parent_local[u] = p;
            nodes.push_back(u);
            order.push_back(u);
            for (int v : graph[u]) {
                if (removed[v] || v == p) {
                    continue;
                }
                stack.push_back({v, u});
            }
        }

        for (int i = static_cast<int>(order.size()) - 1; i >= 0; --i) {
            int u = order[i];
            subtree_size[u] = 1;
            for (int v : graph[u]) {
                if (removed[v] || parent_local[v] != u) {
                    continue;
                }
                subtree_size[u] += subtree_size[v];
            }
        }

        int total = static_cast<int>(nodes.size());
        for (int u : nodes) {
            int max_part = total - subtree_size[u];
            for (int v : graph[u]) {
                if (removed[v] || parent_local[v] != u) {
                    continue;
                }
                max_part = max(max_part, subtree_size[v]);
            }
            if (max_part * 2 <= total) {
                return u;
            }
        }

        return entry;
    }

    void attach_centroid_info(int centroid) {
        vector<array<int, 3>> stack = {{{centroid, -1, 0}}};
        while (!stack.empty()) {
            auto [u, p, d] = stack.back();
            stack.pop_back();
            anc[u].push_back(centroid);
            dist[u].push_back(d);
            for (int v : graph[u]) {
                if (removed[v] || v == p) {
                    continue;
                }
                stack.push_back({v, u, d + 1});
            }
        }
    }

    void decompose(int entry, int parent, int depth) {
        vector<int> nodes;
        int centroid = find_centroid(entry, nodes);

        centroid_parent[centroid] = parent;
        centroid_depth[centroid] = depth;
        attach_centroid_info(centroid);

        removed[centroid] = true;
        for (int v : graph[centroid]) {
            if (!removed[v]) {
                decompose(v, centroid, depth + 1);
            }
        }
    }
};

int main() {
    CentroidDecomposition cd(7);
    cd.add_edge(0, 1);
    cd.add_edge(0, 2);
    cd.add_edge(1, 3);
    cd.add_edge(1, 4);
    cd.add_edge(2, 5);
    cd.add_edge(2, 6);
    cd.build();

    for (int u = 0; u < 7; ++u) {
        cout << u << ":";
        const auto& a = cd.centroid_ancestors(u);
        const auto& d = cd.centroid_distances(u);
        for (int i = 0; i < static_cast<int>(a.size()); ++i) {
            cout << " (" << a[i] << "," << d[i] << ")";
        }
        cout << '\n';
    }
    return 0;
}
