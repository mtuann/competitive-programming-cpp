// Template: HLD path maximum
// Signal: static tree, point updates on nodes, and path maximum queries.
// Assumes: values live on vertices, the aggregate is commutative max, and nodes are 0-indexed.
// Exposes: HLDPathMax with add_edge(u, v), build(values, root), update_node(u, value), and query_path_max(u, v).
// Complexity: O(n) preprocessing, O(log n) update, O(log^2 n) path query.
// Main trap: edge-valued queries or non-commutative path aggregates need a different convention.
// Links:
//   Topic: topics/graphs/hld/README.md
//   Note: practice/ladders/graphs/hld/pathqueries2.md

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct SegmentTreeMax {
    static constexpr int kNegInf = numeric_limits<int>::min();

    int size = 1;
    vector<int> tree;

    explicit SegmentTreeMax(int n) {
        while (size < n) size <<= 1;
        tree.assign(2 * size, kNegInf);
    }

    void build(const vector<int> &values) {
        for (int i = 0; i < static_cast<int>(values.size()); ++i) {
            tree[size + i] = values[i];
        }
        for (int node = size - 1; node >= 1; --node) {
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void set_value(int pos, int value) {
        pos += size;
        tree[pos] = value;
        for (pos >>= 1; pos > 0; pos >>= 1) {
            tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

    int query_inclusive(int left, int right) const {
        int answer = kNegInf;
        left += size;
        right += size;
        while (left <= right) {
            if (left & 1) {
                answer = max(answer, tree[left]);
                ++left;
            }
            if ((right & 1) == 0) {
                answer = max(answer, tree[right]);
                --right;
            }
            left >>= 1;
            right >>= 1;
        }
        return answer;
    }
};

struct HLDPathMax {
    int n;
    vector<vector<int>> graph;
    vector<int> parent;
    vector<int> depth;
    vector<int> subtree_size;
    vector<int> heavy_child;
    vector<int> head;
    vector<int> pos;
    SegmentTreeMax segtree;

    explicit HLDPathMax(int n)
        : n(n),
          graph(n),
          parent(n, -1),
          depth(n, 0),
          subtree_size(n, 1),
          heavy_child(n, -1),
          head(n, 0),
          pos(n, -1),
          segtree(n) {}

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void build(const vector<int> &values, int root = 0) {
        fill(parent.begin(), parent.end(), -1);
        fill(depth.begin(), depth.end(), 0);
        fill(subtree_size.begin(), subtree_size.end(), 1);
        fill(heavy_child.begin(), heavy_child.end(), -1);
        fill(head.begin(), head.end(), 0);
        fill(pos.begin(), pos.end(), -1);

        vector<int> order;
        order.reserve(n);

        vector<int> stack = {root};
        parent[root] = root;
        depth[root] = 0;

        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            order.push_back(u);
            for (int v : graph[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                stack.push_back(v);
            }
        }

        for (int idx = n - 1; idx >= 0; --idx) {
            int u = order[idx];
            int best_size = 0;
            for (int v : graph[u]) {
                if (v == parent[u]) continue;
                subtree_size[u] += subtree_size[v];
                if (subtree_size[v] > best_size) {
                    best_size = subtree_size[v];
                    heavy_child[u] = v;
                }
            }
        }

        vector<int> base(n, SegmentTreeMax::kNegInf);
        vector<int> chain_starts = {root};
        int timer = 0;

        while (!chain_starts.empty()) {
            int start = chain_starts.back();
            chain_starts.pop_back();

            for (int u = start; u != -1; u = heavy_child[u]) {
                head[u] = start;
                pos[u] = timer;
                base[timer] = values[u];
                ++timer;

                for (int v : graph[u]) {
                    if (v == parent[u] || v == heavy_child[u]) continue;
                    chain_starts.push_back(v);
                }
            }
        }

        segtree.build(base);
    }

    void update_node(int u, int value) {
        segtree.set_value(pos[u], value);
    }

    int query_path_max(int u, int v) const {
        int answer = SegmentTreeMax::kNegInf;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            answer = max(answer, segtree.query_inclusive(pos[head[u]], pos[u]));
            u = parent[head[u]];
        }

        if (depth[u] > depth[v]) swap(u, v);
        answer = max(answer, segtree.query_inclusive(pos[u], pos[v]));
        return answer;
    }
};

int main() {
    vector<int> values = {5, 3, 7, 2, 6};
    HLDPathMax hld(static_cast<int>(values.size()));
    hld.add_edge(0, 1);
    hld.add_edge(0, 2);
    hld.add_edge(2, 3);
    hld.add_edge(2, 4);
    hld.build(values);

    cout << hld.query_path_max(1, 4) << '\n';
    hld.update_node(3, 9);
    cout << hld.query_path_max(3, 4) << '\n';
    return 0;
}
