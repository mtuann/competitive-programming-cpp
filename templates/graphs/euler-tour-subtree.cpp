// Template: euler tour subtree sums
// Signal: static rooted tree, point updates on node values, and subtree-sum queries.
// Assumes: nodes are 0-indexed, values live on vertices, the root is fixed, and the tree shape does not change.
// Exposes: EulerTourSubtreeSum with add_edge(u, v), build(values, root), point_set(u, value), point_add(u, delta), subtree_sum(u), and subtree_range(u).
// Complexity: O(n log n) build, O(log n) point update, O(log n) subtree query.
// Main trap: confusing the single-entry subtree tour with the full Euler tour used in some LCA reductions.
// Links:
//   Topic: topics/graphs/euler-tour-subtree/README.md
//   Note: practice/ladders/graphs/euler-tour-subtree/subtreequeries.md

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct Fenwick {
    int n = 0;
    vector<long long> bit;

    explicit Fenwick(int n = 0) {
        init(n);
    }

    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }

    void add(int idx, long long delta) {
        for (++idx; idx <= n; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }

    long long prefix_sum(int right) const {
        long long result = 0;
        for (; right > 0; right -= right & -right) {
            result += bit[right];
        }
        return result;
    }

    long long range_sum(int left, int right) const {
        return prefix_sum(right) - prefix_sum(left);
    }
};

struct EulerTourSubtreeSum {
    int n;
    vector<vector<int>> graph;
    vector<int> parent;
    vector<int> tin;
    vector<int> tout;
    vector<int> order;
    vector<long long> value;
    Fenwick fenwick;

    explicit EulerTourSubtreeSum(int n)
        : n(n),
          graph(n),
          parent(n, -1),
          tin(n, -1),
          tout(n, -1),
          order(n, -1),
          value(n, 0),
          fenwick(n) {}

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void build(const vector<long long>& values, int root = 0) {
        parent.assign(n, -1);
        tin.assign(n, -1);
        tout.assign(n, -1);
        order.assign(n, -1);
        value = values;
        fenwick.init(n);

        vector<int> next_idx(n, 0);
        vector<int> stack = {root};
        parent[root] = root;
        int timer = 0;

        while (!stack.empty()) {
            int u = stack.back();
            if (next_idx[u] == 0) {
                tin[u] = timer;
                order[timer] = u;
                ++timer;
            }

            if (next_idx[u] == static_cast<int>(graph[u].size())) {
                tout[u] = timer;
                stack.pop_back();
                continue;
            }

            int v = graph[u][next_idx[u]++];
            if (v == parent[u]) {
                continue;
            }
            parent[v] = u;
            stack.push_back(v);
        }

        for (int u = 0; u < n; ++u) {
            fenwick.add(tin[u], value[u]);
        }
    }

    pair<int, int> subtree_range(int u) const {
        return {tin[u], tout[u]};
    }

    void point_set(int u, long long new_value) {
        long long delta = new_value - value[u];
        value[u] = new_value;
        fenwick.add(tin[u], delta);
    }

    void point_add(int u, long long delta) {
        value[u] += delta;
        fenwick.add(tin[u], delta);
    }

    long long subtree_sum(int u) const {
        return fenwick.range_sum(tin[u], tout[u]);
    }
};

int main() {
    vector<long long> values = {4, 2, 5, 2, 1};
    EulerTourSubtreeSum tree(static_cast<int>(values.size()));
    tree.add_edge(0, 1);
    tree.add_edge(0, 2);
    tree.add_edge(2, 3);
    tree.add_edge(2, 4);
    tree.build(values);

    cout << tree.subtree_sum(2) << '\n';
    tree.point_set(4, 3);
    cout << tree.subtree_sum(2) << '\n';
    return 0;
}
