// Problem: Dynamic Connectivity
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2133
// Topic: DSU rollback, segment tree over time, offline dynamic connectivity
// Idea: turn every edge into one active interval over graph states
// t = 0..k, place each interval on a segment tree over time, DFS that tree,
// and maintain component count with a rollback-friendly DSU.

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct DSURollback {
    struct Change {
        int root_a;
        int root_b;
        int size_a_before;
    };

    int components;
    vector<int> parent;
    vector<int> size;
    vector<Change> history;

    explicit DSURollback(int n) : components(n), parent(n), size(n, 1) {
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

    int snapshot() const {
        return static_cast<int>(history.size());
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            history.push_back({-1, -1, -1});
            return;
        }
        if (size[a] < size[b]) {
            swap(a, b);
        }
        history.push_back({a, b, size[a]});
        parent[b] = a;
        size[a] += size[b];
        --components;
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
    int states;
    vector<vector<pair<int, int>>> seg;

    explicit OfflineDynamicConnectivity(int states) : states(states), seg(4 * max(1, states)) {}

    void add_interval(int l, int r, pair<int, int> edge) {
        if (l >= r) {
            return;
        }
        add_interval(1, 0, states, l, r, edge);
    }

    void run(DSURollback& dsu, vector<int>& ans) const {
        dfs(1, 0, states, dsu, ans);
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

    void dfs(int node, int left, int right, DSURollback& dsu, vector<int>& ans) const {
        int snap = dsu.snapshot();
        for (auto [u, v] : seg[node]) {
            dsu.unite(u, v);
        }

        if (right - left == 1) {
            ans[left] = dsu.components;
        } else {
            int mid = (left + right) / 2;
            dfs(node * 2, left, mid, dsu, ans);
            dfs(node * 2 + 1, mid, right, dsu, ans);
        }

        dsu.rollback(snap);
    }
};

static long long edge_key(int u, int v) {
    if (u > v) {
        swap(u, v);
    }
    return (static_cast<long long>(u) << 32) ^ static_cast<unsigned int>(v);
}

static pair<int, int> decode_edge(long long key) {
    int u = static_cast<int>(key >> 32);
    int v = static_cast<int>(key & 0xffffffffu);
    return {u, v};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    const int states = k + 1;
    OfflineDynamicConnectivity odc(states);
    unordered_map<long long, int> active_since;
    active_since.reserve(static_cast<size_t>(m + k) * 2 + 7);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        active_since[edge_key(u, v)] = 0;
    }

    for (int i = 1; i <= k; ++i) {
        int type, u, v;
        cin >> type >> u >> v;
        --u;
        --v;
        long long key = edge_key(u, v);

        if (type == 1) {
            active_since[key] = i;
        } else {
            int start = active_since[key];
            odc.add_interval(start, i, decode_edge(key));
            active_since.erase(key);
        }
    }

    for (const auto& [key, start] : active_since) {
        odc.add_interval(start, states, decode_edge(key));
    }

    DSURollback dsu(n);
    vector<int> ans(states, 0);
    odc.run(dsu, ans);

    for (int i = 0; i < states; ++i) {
        cout << ans[i] << (i + 1 == states ? '\n' : ' ');
    }
    return 0;
}
