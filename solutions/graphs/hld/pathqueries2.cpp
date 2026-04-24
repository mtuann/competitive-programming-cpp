// Problem: Path Queries II
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2134
// Topic: heavy-light decomposition, segment tree, tree path maximum
// Idea: flatten each heavy chain into a contiguous base-array segment. A point
// update changes one position, and a path query climbs chain heads while
// merging O(log N) segment-tree maximum queries.

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct SegmentTree {
    static constexpr int kNegInf = numeric_limits<int>::min();

    int size;
    vector<int> tree;

    explicit SegmentTree(int n) : size(1) {
        while (size < n) {
            size <<= 1;
        }
        tree.assign(2 * size, kNegInf);
    }

    void build(const vector<int>& values) {
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

    int query(int left, int right) const {
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

struct HeavyLightDecomposition {
    int n;
    int timer;
    vector<vector<int>> graph;
    vector<int> parent;
    vector<int> depth;
    vector<int> subtree_size;
    vector<int> heavy_child;
    vector<int> head;
    vector<int> pos;

    explicit HeavyLightDecomposition(int n)
        : n(n),
          timer(0),
          graph(n + 1),
          parent(n + 1, 0),
          depth(n + 1, 0),
          subtree_size(n + 1, 1),
          heavy_child(n + 1, 0),
          head(n + 1, 0),
          pos(n + 1, -1) {}

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> build(const vector<int>& value) {
        vector<int> order;
        order.reserve(n);

        vector<int> stack;
        stack.reserve(n);
        stack.push_back(1);
        parent[1] = 0;

        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            order.push_back(u);
            for (int v : graph[u]) {
                if (v == parent[u]) {
                    continue;
                }
                parent[v] = u;
                depth[v] = depth[u] + 1;
                stack.push_back(v);
            }
        }

        for (int idx = n - 1; idx >= 0; --idx) {
            int u = order[idx];
            int best_size = 0;
            for (int v : graph[u]) {
                if (v == parent[u]) {
                    continue;
                }
                subtree_size[u] += subtree_size[v];
                if (subtree_size[v] > best_size) {
                    best_size = subtree_size[v];
                    heavy_child[u] = v;
                }
            }
        }

        vector<int> base_array(n);
        vector<int> chain_starts;
        chain_starts.reserve(n);
        chain_starts.push_back(1);

        while (!chain_starts.empty()) {
            int start = chain_starts.back();
            chain_starts.pop_back();

            for (int u = start; u != 0; u = heavy_child[u]) {
                head[u] = start;
                pos[u] = timer;
                base_array[timer] = value[u];
                ++timer;

                for (int v : graph[u]) {
                    if (v == parent[u] || v == heavy_child[u]) {
                        continue;
                    }
                    chain_starts.push_back(v);
                }
            }
        }

        return base_array;
    }

    int query_path(int u, int v, const SegmentTree& segtree) const {
        int answer = SegmentTree::kNegInf;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) {
                swap(u, v);
            }
            answer = max(answer, segtree.query(pos[head[u]], pos[u]));
            u = parent[head[u]];
        }

        if (depth[u] > depth[v]) {
            swap(u, v);
        }
        answer = max(answer, segtree.query(pos[u], pos[v]));
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> value(n + 1);
    for (int node = 1; node <= n; ++node) {
        cin >> value[node];
    }

    HeavyLightDecomposition hld(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        hld.add_edge(u, v);
    }

    vector<int> base_array = hld.build(value);
    SegmentTree segtree(n);
    segtree.build(base_array);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            segtree.set_value(hld.pos[s], x);
        } else {
            int a, b;
            cin >> a >> b;
            cout << hld.query_path(a, b, segtree) << '\n';
        }
    }

    return 0;
}
