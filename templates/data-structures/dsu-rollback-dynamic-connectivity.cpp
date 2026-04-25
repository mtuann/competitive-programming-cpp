// Template: DSU Rollback / Offline Dynamic Connectivity
// Signal: connectivity or component-count queries under an add/remove edge
// timeline, where the whole event sequence is known in advance.
// Assumes: all updates are offline; undirected edges are normalized before
// interval extraction; rollback uses union by size without ordinary path compression.
// Exposes: DSURollback with snapshot(), rollback(), unite(), same(), and components,
// plus OfflineDynamicConnectivity with add_active_interval() and run().
// Complexity: O(total interval placements * log n), i.e. O((events log q) log n) with the safe starter.
// Main trap: modeling edge lifetimes with the wrong half-open interval, or using ordinary path compression.
// Links:
//   Topic: topics/data-structures/dsu-rollback/README.md
//   Note: practice/ladders/data-structures/dsu-rollback/dynamicconnectivity.md

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct DSURollback {
    struct Change {
        int root_a;
        int root_b;
        int size_a_before;
    };

    int n;
    int components;
    vector<int> parent;
    vector<int> size;
    vector<Change> history;

    explicit DSURollback(int n) : n(n), components(n), parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) const {
        while (parent[x] != x) {
            x = parent[x];
        }
        return x;
    }

    bool same(int a, int b) const {
        return find(a) == find(b);
    }

    int snapshot() const {
        return static_cast<int>(history.size());
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            history.push_back({-1, -1, -1});
            return false;
        }
        if (size[a] < size[b]) {
            swap(a, b);
        }
        history.push_back({a, b, size[a]});
        parent[b] = a;
        size[a] += size[b];
        --components;
        return true;
    }

    void rollback(int snap) {
        while (static_cast<int>(history.size()) > snap) {
            Change ch = history.back();
            history.pop_back();
            if (ch.root_a == -1) {
                continue;
            }
            parent[ch.root_b] = ch.root_b;
            size[ch.root_a] = ch.size_a_before;
            ++components;
        }
    }
};

struct OfflineDynamicConnectivity {
    int time_states;
    vector<vector<pair<int, int>>> seg;

    explicit OfflineDynamicConnectivity(int time_states)
        : time_states(time_states), seg(4 * max(1, time_states)) {}

    void add_active_interval(int l, int r, int u, int v) {
        if (l >= r) {
            return;
        }
        add_interval(1, 0, time_states, l, r, {u, v});
    }

    template <class LeafHandler>
    void run(DSURollback& dsu, LeafHandler&& handle_leaf) const {
        dfs(1, 0, time_states, dsu, handle_leaf);
    }

private:
    void add_interval(int node, int left, int right, int ql, int qr, pair<int, int> edge) {
        if (qr <= left || right <= ql) {
            return;
        }
        if (ql <= left && right <= qr) {
            seg[node].push_back(edge);
            return;
        }
        int mid = (left + right) / 2;
        add_interval(node * 2, left, mid, ql, qr, edge);
        add_interval(node * 2 + 1, mid, right, ql, qr, edge);
    }

    template <class LeafHandler>
    void dfs(int node, int left, int right, DSURollback& dsu, LeafHandler& handle_leaf) const {
        int snap = dsu.snapshot();
        for (auto [u, v] : seg[node]) {
            dsu.unite(u, v);
        }

        if (right - left == 1) {
            handle_leaf(left, dsu);
        } else {
            int mid = (left + right) / 2;
            dfs(node * 2, left, mid, dsu, handle_leaf);
            dfs(node * 2 + 1, mid, right, dsu, handle_leaf);
        }

        dsu.rollback(snap);
    }
};

int main() {
    const int time_states = 4;  // states 0, 1, 2, 3
    OfflineDynamicConnectivity odc(time_states);
    DSURollback dsu(4);
    vector<int> answers(time_states, -1);

    odc.add_active_interval(0, 4, 0, 1);  // alive in every state
    odc.add_active_interval(1, 3, 2, 3);  // alive only in states 1 and 2

    odc.run(dsu, [&](int t, const DSURollback& cur) {
        answers[t] = cur.components;
    });

    for (int t = 0; t < time_states; ++t) {
        cout << answers[t] << (t + 1 == time_states ? '\n' : ' ');
    }
    return 0;
}
